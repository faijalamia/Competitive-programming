class DatabaseConnection:
    __instance = None

    def __new__(cls):
        if cls.__instance is None:
            print("Creating new DatabaseConnection instance...")
            cls.__instance = super(DatabaseConnection, cls).__new__(cls)
            cls.__instance.connection = cls.__connect()
        return cls.__instance

    @staticmethod
    def __connect():
        # Simulate establishing a database connection
        return "Database connection established"

    def get_connection(self):
        return self.connection

db1 = DatabaseConnection()
print(db1.get_connection())

db2 = DatabaseConnection()
print(db2.get_connection())

print("Are both instances the same?", db1 is db2)  # True