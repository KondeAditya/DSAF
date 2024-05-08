class TelephoneBook:
    def __init__(self, name, tel_no):
        self.name = name
        self.tel_no = tel_no

def insert_linear_probing(hashtable, records):
    for name, tel_no in records:
        hash_value = tel_no % 10
        while hashtable[hash_value] is not None:
            hash_value = (hash_value + 1) % 10
        hashtable[hash_value] = TelephoneBook(name, tel_no)

def insert_double_hashing(hashtable, records):
    for name, tel_no in records:
        hash_value = tel_no % 10
        j = 1
        while hashtable[hash_value] is not None:
            hash_value = ((tel_no % 9) + (j * (7 - (tel_no % 7)))) % 10
            '''
            hf1 = hv mod (n-1)
            hf2 = m - (hv mod m) ...m is nearest prime no to size
            hv= hf1+(j*hf2)
            '''
            j += 1
        hashtable[hash_value] = TelephoneBook(name, tel_no)

def display(hashtable):
    print("-------------------------------")
    print("Index\tName\tTelephone No.")
    print("-------------------------------")
    index = 0
    for entry in hashtable:
        if entry is None:
            print(index, "\t-\t-")
        else:
            print(index, "\t", entry.name, "\t", entry.tel_no)
        index += 1
    print("-------------------------------")

def search(hashtables, name):
    found = False
    idx = 1
    for hashtable in hashtables:
        index = 0
        for entry in hashtable:
            if entry is not None and entry.name == name:
                print(f"\nFound in Hashtable-{idx}!")
                print("-------------------------------")
                print("Index\tName\tTelephone No.")
                print("-------------------------------")
                print(index, "\t", entry.name, "\t", entry.tel_no)
                print("-------------------------------")
                found = True
            index += 1
        idx += 1
    if not found:
        print("\nNot found!")

def main():
    hashtable_linear = [None] * 10
    hashtable_double = [None] * 10
    while True:
        print("-------------------------")
        print("\t1.Insert Values")
        print("\t2.Display")
        print("\t3.Search")
        print("\t4.Exit")
        print("-------------------------")
        choice = int(input("Enter choice : "))

        if choice == 1:
            print("\nSelect collision method-")
            print("\t1.Linear Probing")
            print("\t2.Double Hashing")

            collision_choice = int(input("Enter choice : "))
            num_records = int(input("Enter number of records to insert: "))
            records = []

            for _ in range(num_records):
                name = input("Enter name : ")
                tel_no = int(input("Enter telephone no. : "))
                records.append((name, tel_no))
            if collision_choice == 1:
                insert_linear_probing(hashtable_linear, records)
            elif collision_choice == 2:
                insert_double_hashing(hashtable_double, records)

        elif choice == 2:
            print("\t1.Display Linear Probing")
            print("\t2.Display Double Hashing")
            display_choice = int(input("Enter choice : "))
            if display_choice == 1:
                display(hashtable_linear)
            elif display_choice == 2:
                display(hashtable_double)

        elif choice == 3:
            name = input("Enter name to search: ")
            search([hashtable_linear, hashtable_double], name)

        elif choice == 4:
            break
        else:
            print("! Enter valid choice.")
main()