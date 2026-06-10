import sys

"""
File: credit_card_total.py
--------------------------
This program totals up a credit card bill based on
how much was spent at each store on the bill.
"""


def bill_calculation(bill_file:str) -> dict[str, int]:
    bill = {}

    with open(bill_file,"r") as file:
        for line in file:
            _,info = line.rstrip().split("[")
            store,amount = info.split("] $")
            if store in bill:
                bill[store] += int(amount)
            else:
                bill[store] = int(amount)

    return bill

def main():
    if(len(sys.argv)<2):
        sys.exit("Too few arguments")
    if(len(sys.argv)>2):
        sys.exit("Too many arguments")

    try:
        final_bill = bill_calculation(sys.argv[1])
    except FileNotFoundError:
        sys.exit("input correct filename")
    
    for store , amount in final_bill.items():
        print(f"{store}:" , f"${amount}")
    

# to call the main() function.
if __name__ == '__main__':
    main()
