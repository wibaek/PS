class Node:
  global tree
  def __init__(self, item: str, lchild: str, rchild: str):
    self.item = item
    self.lchild = lchild
    self.rchild = rchild
  def getItem(self) -> str:
    return self.item
  def getLchild(self) -> str:
    return self.lchild
  def getRchild(self) -> str:
    return self.rchild

def preOrder(node: Node):
  print(node.getItem(), end="")
  if node.getLchild() != '.':
    preOrder(tree[node.getLchild()])
  if node.getRchild() != '.':
    preOrder(tree[node.getRchild()])

def inOrder(node: Node):
  if node.getLchild() != '.':
    inOrder(tree[node.getLchild()])
  print(node.getItem(), end="")
  if node.getRchild() != '.':
    inOrder(tree[node.getRchild()])

def postOrder(node: Node):
  if node.getLchild() != '.':
    postOrder(tree[node.getLchild()])
  if node.getRchild() != '.':
    postOrder(tree[node.getRchild()])
  print(node.getItem(), end="")
  
def solution():
  global tree
  tree = {}
  N = int(input())
  for _ in range(N):
    data = input().split()
    tree[data[0]] = Node(data[0], data[1], data[2])
  preOrder(tree['A'])
  print()
  inOrder(tree['A'])
  print()
  postOrder(tree['A'])

solution()