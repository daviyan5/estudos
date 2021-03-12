hrs = input("Enter Hours:")
rat = input("Enter Rate:")
h = float(hrs)
rate = float(rat)
if h>40:
    pay=40* rate + (h-40)*1.5*rate
    print(pay)
else:
    pay=h * rate
    print(pay)
    