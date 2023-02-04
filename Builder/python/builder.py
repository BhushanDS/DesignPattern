

class Builder:
    def getWheel(self):pass
    def getBody(self):pass
    def getEngine(self):pass

#wholeProduct

class Car(Builder):
    def __init__(self):
        self.__wheels = list()