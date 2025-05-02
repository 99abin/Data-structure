class node:
    def __init__(self, data, next):
        self.data = data
        self.next = next

class queue:
    def __init__(self):
        self.head = None
        self.tail = None
    
    def enqueue(self, data):
        if self.head == None:
            newnode = node(data, None)
            self.head = self.tail = newnode
        else:
            newnode = node(data, None)
            self.tail.next = newnode
            self.tail = newnode
    
    def dequeue(self):
        if self.head == None:
            return
        else:
            temp = self.head.next
            self.head.next = None
            self.head = temp
    
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
            print('Queue is empty')
        else:
            itr = self.head
            qstring = ' '
            while itr != None:
                qstring += '[' + str(itr.data) + ']'
                itr = itr.next
            print(qstring)
            
            
# -----MAIN-----
q = queue()
q.enqueue(3)
q.enqueue(5)
q.enqueue(8)
q.dequeue()

q.length()
q.print()
