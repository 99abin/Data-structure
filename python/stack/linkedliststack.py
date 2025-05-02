class node:
    def __init__(self, data, next):
        self.data = data
        self.next = next
        
class stack:
    def __init__(self):
        self.head = None
        self.rear = None
    
    def push(self, data):
        if self.head == None:
            newnode = node(data, None)
            self.head = newnode
            self.rear = newnode
        else:
            newnode = node(data, None)
            self.rear.next = newnode
            self.rear = newnode
    
    def pop(self):
        if self.head == None:
            return
        else:
            itr = self.head
            while itr.next.next != None:
                itr = itr.next
            self.rear = itr
            itr.next = None
            
    def length(self):
        if self.head == None:
            print('0')
        else:
            itr = self.head
            count = 0
            while itr!= None:
                itr = itr.next
                count += 1
            print('Stack length is:', count)
        
    def print(self):
        if self.head == None:
            print('Stack is empty')
        else:
            itr = self.head
            sstring = ' '
            while itr != None:
                sstring += '[' + str(itr.data) + ']'
                itr = itr.next
            print(sstring)
            
# ------MAIN------
s = stack()
s.push(10)
s.push(17)
s.push(22)
s.pop()
s.push(49)

s.length()
s.print()
