from abc import ABC, abstractmethod

class PaymentStrategy(ABC):
    @abstractmethod
    def pay(self, amount):
        pass

class CreditCardPayment(PaymentStrategy):
    def pay(self, amount):
        print(f"Paid ${amount} using Credit Card.")

class PayPalPayment(PaymentStrategy):
    def pay(self, amount):
        print(f"Paid ${amount} using PayPal.")

class BankTransferPayment(PaymentStrategy):
    def pay(self, amount):
        print(f"Paid ${amount} using Bank Transfer.")


class PaymentProcessor:
    def __init__(self, strategy: PaymentStrategy):
        self.strategy = strategy

    def set_strategy(self, strategy: PaymentStrategy):
        self.strategy = strategy

    def process_payment(self, amount):
        self.strategy.pay(amount)


# Product Base Class
class Product:
    def __init__(self, name, price):
        self.name = name
        self.price = price

# Factory
class ProductFactory:
    @staticmethod
    def create_product(product_type):
        if product_type == "Book":
            return Product("Book", 15.99)
        elif product_type == "Laptop":
            return Product("Laptop", 999.99)
        elif product_type == "Headphones":
            return Product("Headphones", 79.99)
        else:
            raise ValueError("Unknown product type.")



def main():
    product_type = input("Enter product type (Book, Laptop, Headphones): ")
    product = ProductFactory.create_product(product_type)
    print(f"Product created: {product.name}, Price: ${product.price}")

    print("Choose payment method: 1. Credit Card 2. PayPal 3. Bank Transfer")
    choice = input("Enter choice (1/2/3): ")

    if choice == "1":
        strategy = CreditCardPayment()
    elif choice == "2":
        strategy = PayPalPayment()
    elif choice == "3":
        strategy = BankTransferPayment()
    else:
        print("Invalid choice. Using Credit Card by default.")
        strategy = CreditCardPayment()

    processor = PaymentProcessor(strategy)
    processor.process_payment(product.price)

if __name__ == "__main__":
    main()
