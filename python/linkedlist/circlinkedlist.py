class node:
    def __init__(self, fdata = None, fnext = None):
        self.data = fdata
        self.next = fnext
    
class circlinkedlist:
    def __init__(self):
        self.tail = None
        
    def insert_front(self, data):
        newnode = node(data, None)
        if self.tail == None:
            newnode.next = newnode
            self.tail = newnode
        else:
            newnode.next = self.tail.next
            self.tail.next = newnode
    
    def insert_rear(self, data):
        newnode = node(data, None)
        if self.tail == None:
            newnode.next = newnode
            self.tail = newnode
        else:
            newnode.next = self.tail.next
            self.tail.next = newnode
            self.tail = newnode
    
    def insert_at(self, index, data):
        if self.tail == None:
            print("index didn't exist")
        else:
            itr = self.tail.next
            count = 1
            if count == index:
                newnode = node(data, self.tail.next.next)
                self.tail.next.next = newnode
                return
            if index == 0:
                self.insert_front(data)
            while (count != index and itr != self.tail.next) or count == 1:
                itr = itr.next
                count += 1
            if itr == self.tail.next:
                print("index didn't exist")
            else:
                newnode = node(data, itr.next)
                itr.next = newnode
    
    def delete_at(self, index):
        if self.tail == None:
            print("index didn't exist")
        else:
            if index == 0:
                self.tail.next = self.tail.next.next
                return
            elif index == 1:
                self.tail.next.next = self.tail.next.next.next
                return
            itr = self.tail.next
            count = 1
            while (count != index and itr != self.tail.next) or count == 1:
                itr = itr.next
                count += 1
            if itr.next == self.tail.next:
                print("index didn't exist")
            else:
                itr.next = itr.next.next
            
    def length(self):
        if self.tail == None:
            print('0')
        else :
            itr = self.tail.next
            count = 1
            while itr.next != self.tail.next:
                itr = itr.next
                count += 1
            print('length of the circular linkedlist:', count)
            
    def print(self):
        if self.tail == None:
            print('linkedlist is empty')
        else:
            itr = self.tail.next.next
            cllstr = '-->[' + str(self.tail.next.data) + ']--'
            while itr != self.tail.next:
                cllstr += '-->[' + str(itr.data) + ']' + '--'
                itr = itr.next
            print(cllstr)
            
# -----MAIN-----
cll = circlinkedlist()
cll.insert_front(3)
cll.insert_rear(4)
cll.insert_front(7)
cll.insert_at(3, 10)
cll.delete_at(3)
cll.insert_at(2, 75)

cll.length()
cll.print()
