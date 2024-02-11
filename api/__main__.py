from bs4 import BeautifulSoup
import json
from typing import Dict
import re
import requests
from requests.models import Response


def get_content_from_element(response: str,
                             tag_name: str,
                             tag_attrs: Dict,
                             tag_content: str) -> str:
  """Fetches the content from a specified html element.

  Args:
      name: The name of the element.
      attrs: The element attributes.
      content: The content attribute to return.

  Returns:
      The content text.
  """
  soup = BeautifulSoup(response.text, 'html.parser')
  element = soup.head.find(tag_name, tag_attrs)
  return element.get(tag_content)


def connect_to_endpoint(url: str) -> Response:
  """Request a page from LeetCode.

  Args:
      url: The base url.

  Returns:
      The response text.
  """
  response: Response = requests.get(url)

  if response.status_code != 200:
    raise Exception(response.status_code, response.text)
  return response


def parse_problem(desc: str):
  sections = {}
  trim_newlines = lambda s: '\n'.join(line for line in s.split('\n') if line.strip())
  line_desc = trim_newlines(desc)


  pattern = re.compile(r'Example \d+:|Constraints:')
  matches = pattern.finditer(line_desc)
  positions = [(match.group(), match.start()) for match in matches]

  sections["Description"] = line_desc[:positions[0][1]]
  prev = positions[0][1]
  for group, pos in positions:
    # print(f"GROUP: {group}, POS: {pos}")
    sections[group] = line_desc[prev: pos]
    prev = pos
  sections["Constraints"] = line_desc[prev:]

  images = []
  for k in sections:
    # Search for image urls in each example
    image_url = re.compile(r'\[https://.*\.jpg\]').search(sections[k])
    if image_url:
      # Strip square brackets
      images.append(image_url.group()[1:-1])

  print(images)

def main():
  url = "https://leetcode.com/problems/reverse-linked-list/"
  # url = "https://leetcode.com/problems/number-of-islands/"
  tag_name = 'meta'
  tag_attrs = {'name': 'description'}
  tag_content = 'content'

  response = connect_to_endpoint(url)
  description = get_content_from_element(response,
                                         tag_name,
                                         tag_attrs,
                                         tag_content)
  # print(description)
  parse_problem(description)

main()
# if __name__ == '__main__':
#   main()
