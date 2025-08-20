from abc import ABC, abstractmethod

class IceCream(ABC):
    @abstractmethod
    def get_description(self) -> str:
        pass

    @abstractmethod
    def get_cost(self) -> float:
        pass


class VanillaIceCream(IceCream):
    def get_description(self) -> str:
        return "Vanilla Ice Cream"

    def get_cost(self) -> float:
        return 5.0

class ChocolateIceCream(IceCream):
    def get_description(self) -> str:
        return "Chocolate Ice Cream"

    def get_cost(self) -> float:
        return 6.0


class ToppingDecorator(IceCream, ABC):
    def __init__(self, ice_cream: IceCream):
        self._ice_cream = ice_cream

    def get_description(self) -> str:
        return self._ice_cream.get_description()

    def get_cost(self) -> float:
        return self._ice_cream.get_cost()


class ChocolateChips(ToppingDecorator):
    def get_description(self) -> str:
        return f"{self._ice_cream.get_description()}, Chocolate Chips"

    def get_cost(self) -> float:
        return self._ice_cream.get_cost() + 1.5

class CashewNuts(ToppingDecorator):
    def get_description(self) -> str:
        return f"{self._ice_cream.get_description()}, Cashew Nuts"

    def get_cost(self) -> float:
        return self._ice_cream.get_cost() + 2.0


def main():
    
    order1 = ChocolateChips(VanillaIceCream())
    print(f"Order: {order1.get_description()}")
    print(f"Cost: ${order1.get_cost():.2f}")

    
    order2 = CashewNuts(ChocolateChips(ChocolateIceCream()))
    print(f"Order: {order2.get_description()}")
    print(f"Cost: ${order2.get_cost():.2f}")

if __name__ == "__main__":
    main()