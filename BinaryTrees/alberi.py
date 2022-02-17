class Node:
    def __init__(self, data):
        self.left = None
        self.right = None
        self.val = data

    def printTree(self):
        if self.left:
            self.left.printTree()
            
        print(self.val)
        
        if self.right:
            self.right.printTree()

    def insert(self, data):
        if self.val:
            if data < self.val:
                if self.left is None:
                    self.left = Node(data)
                else:
                    self.left.insert(data)
            elif data > self.val: 
                if self.right is None:
                    self.right = Node(data)
                else:
                    self.left.insert(data)
        else:
            self.val = data

root = Node(10)
root.insert(32)
root.insert(1)   
root.printTree()
