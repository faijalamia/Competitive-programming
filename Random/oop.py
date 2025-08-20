class Student:
    def set_value(self,a,b):
        self.roll = a
        self.gpa = b

    def display(self):
        print(f"Roll = {self.roll}, GPA = {self.gpa}")


kamal = Student()
kamal.set_value(10,3.75)
kamal.display()

