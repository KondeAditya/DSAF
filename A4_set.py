A=set(())
B=set(())

def insert():
    numA = int(input("Enter count of eles to insert in A: "))
    for i in range(numA):
        ele=int(input("Enter element: "))
        A.add(ele)
    print(A)

    numB = int(input("Enter count of eles to insert in B: "))
    for i in range(numB):
        ele = int(input("Enter element: "))
        B.add(ele)
    print(B)

def dele():
    d=int(input("Enter element to delete from set A: "))
    if d in A:
        A.discard(d)
        print("Element deleted")
    else:
        print("No such element")
    print(A)

def srch():
    key=int(input("Enter element to be searched in set B: "))
    if key in B:
        return True
    else:
        return "Element not found!"

def size():
    countA=0
    countB=0
    for i in A:
        countA+=1
    print(f"Size of Set A: {countA}")

    for i in B:
        countB+=1
    print(f"Size of Set B: {countB}")
    

def uni():
    uni=[]
    for i in A:
        uni.append(i)

    for i in B:
        uni.append(i)
    uni=set(uni)
    print("Union of sets: ",uni)

def intersect():
    inti=[]
    for i in A:
        for i in B:
            if i in A and i in B:
                inti.append(i)
    inti=set(inti)
    print("Intersection of sets: ",inti)

def diff():
    diffA=[]
    for i in A:
            if i not in B:
                diffA.append(i)
    diffA=set(diffA)
    print("A-B: ",diffA)

def subset():
    if B<=A:
        print("Subset of A")
    else:
        print("Not a Subset")
exit=0

print("---------MENU------------")
print("1.INSERT\n2.DELETE\n3.SEARCH\n4.SIZE\n5.UNION\n"
      "6.INTERSECTION\n7.DIFFERENCE\n8.SUBSET\n9.EXIT")
while(exit!=1):
    ch=int(input("Enter ur choice: "))
    if ch==1:
        insert()
    elif ch==2:
        dele()
    elif ch==3:
        print(srch())
    elif ch==4:
        size()
    elif ch==5:
        uni()
    elif ch==6:
        intersect()
    elif ch==7:
        diff()
    elif ch==8:
        subset()
    elif ch==9:
        exit=1
    else:
        print("Invalid Choice Entered!")