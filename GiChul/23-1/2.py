class Node:
    def __init__(self, data, next):
        self.data = data
        self.next = next

#s = [8,1,2,3,3,2,1,4,9,4,5,6,7,6,5,4,1]
s = [8,1,2,3,3,2,1,0,4,9,1,2,3,3,2,1,9,1]
#s = [1,2,3,2,1]

head = Node(s[-1], None)
for i in range(len(s)-1):
    head = Node(s[-2-i], head)

t = [2,1,0,4,7]
head2 = Node(t[-1], None)
for i in range(len(t)-1):
    head2 = Node(t[-2-i], head2)
    
def print_list(s: Node) -> None:
    node = s
    print('[', end='')
    while(node!=None):
        print(f'{node.data}, ' if node.next!=None else f'{node.data}', end='')
        node = node.next
    print(']', end='')

print_list(head)
print()

def palindrome(s: Node) -> int:
    slist = []
    node = s

    while(node!=None):
        slist.append(node.data)
        node = node.next
    
    return int(slist[:len(slist)//2]==slist[:(len(slist)-1)//2:-1])

print(palindrome(head))

def sub_list(s: Node, t: Node) -> int:
    s_node = s
    s_save = s
    t_node = t
    while(s_node!=None):
        if(s_node.data!=t_node.data):
            s_node = s_save.next
            s_save = s_node
            t_node = t
        else:
            s_node = s_node.next
            t_node = t_node.next
            if(t_node==None): return 1
        
    return 0
    
print(sub_list(head,head2))

def make_sublist(s: Node, start: int, end: int) -> Node:
    i = 0
    node = s
    sublist_head = Node(0, None)
    sublist = sublist_head

    while(i<end):
        if i==start:
            sublist_head = Node(node.data, None)
            sublist = sublist_head
        else: 
            next = Node(node.data, None)
            sublist.next = next
            sublist = sublist.next

        i+=1
        node = node.next
    
    return sublist_head


def max_palindrome(s: Node) -> None:
    s_node = s
    s_save = s
    test = Node(s.data,None)
    test_head = test
    palin_list = []
    start = 0
    end = 1

    while(1):
        while(1):
            if(palindrome(test_head)):
                node = test_head
                palin_list.append([start,end])

            if s_node.next==None: break
            else:    
                s_node = s_node.next
                test.next = Node(s_node.data,None)
                test = test.next
                end+=1
        
        if s_save.next==None: break
        else: 
            s_node = s_save.next
            s_save = s_node
            test = Node(s_node.data,None)
            test_head = test
            start += 1
            end = start+1

    i=0
    while(i<len(palin_list)):
        for j in range(len(palin_list)):
            if(i!=j):
                slist = make_sublist(s,palin_list[j][0],palin_list[j][1])
                tlist = make_sublist(s,palin_list[i][0],palin_list[i][1])
                if(sub_list(slist,tlist)):
                    palin_list.pop(i)
                    i-=1
                    break
        i+=1

    print('[', end='')
    for rng in palin_list:
        print_list(make_sublist(s,rng[0],rng[1]))
        print(', ' if rng!=palin_list[-1] else '', end='')
    print(']', end='')

max_palindrome(head)
