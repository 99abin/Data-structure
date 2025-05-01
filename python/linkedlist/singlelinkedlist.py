class node:
    def __init__(self, fdata = None, fnext = None):
        self.data = fdata
        self.next = fnext
    
class linkedlist:
    def __init__(self):
        self.head = None
        
    def insert_front(self, data):
        newnode = node(data, self.head)
        self.head = newnode
    
    def insert_rear(self, data):
        if self.head == None:
            newnode = node(data, None)
            self.head = newnode
        else:
            itr = self.head
            while itr.next != None:
                itr = itr.next
            newnode = node(data, None)
            itr.next = newnode
    
    def insert_at(self, index, data):
        if self.head == None:
            newnode = node(data, None)
        else: 
            itr = self.head
            count = 1
            while count != index and itr != None:
                itr = itr.next
                count += 1
            if itr == None:
                insert_rear(data)
            else:
                newnode = node(data, itr.next)
                itr.next = newnode
    
    def delete_at(self, index):
        if self.head == None:
            return
        itr = self.head
        count = 1
        while count != index and itr != None:
            itr = itr.next
            count += 1
        if itr == None:
            return
        else:
            itr.next = itr.next.next
            
    def length(self):
        if self.head == None:
            print('linkedlist is empty')
        else :
            itr = self.head
            count = 0
            while itr != None:
                itr = itr.next
                count += 1
            print('length of the linkedlist:', count)
            
    def print(self):
        if self.head == None:
            print('linkedlist is empty')
        else:
            itr = self.head
            llstr = ' '
            while itr != None:
                llstr += '[' + str(itr.data) + ']' + '--->'
                itr = itr.next
            print(llstr + '[NULL]')
            
# -----MAIN-----
ll = linkedlist()
ll.insert_front(3)
ll.insert_rear(4)
ll.insert_front(7)
ll.insert_at(2, 10)
ll.delete_at(2)

ll.length()
ll.print()
