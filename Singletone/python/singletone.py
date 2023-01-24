class Singletone(object):
    def __new__(cls):
        if not hasattr(cls,'instance'):
            print("Inside constrctor")
            cls.instance = super(Singletone,cls).__new__(cls)
        return cls.instance

obj = Singletone()
new_obj = Singletone()

print(obj is new_obj)
