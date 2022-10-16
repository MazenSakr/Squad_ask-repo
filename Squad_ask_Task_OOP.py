import math
import turtle
import cv2
import numpy as np


class Polygon:
    def __init__(self,side_number,side_length):
        self.__side_number = side_number
        self.__side_length = side_length
    def Get_Side_Number(self):
        return self.__side_number
    def Get_Side_Length(self):
        return self.__side_length
    def Area(self):
        Apothem = (self.__side_length/(2*math.tan(math.radians(180/self.__side_number))))
        print(f"The Area =",(self.__side_number *self.__side_length*Apothem)/2)
    def Perimeter(self):
        print(f"The Perimeter =",(self.__side_number*self.__side_length))
    def Draw(self):
        pass
class Pentagon(Polygon):
    def __init__(self,side_length):
        side_number=5
        super().__init__(side_number,side_length)
    def Draw(self):
        d=self.Get_Side_Length()
        t = turtle.Turtle()
        for i in range(5):
            t.forward(d)
            t.right(72) #Turning the turtle by 72 degree   
class Hexagon(Polygon):
    def __init__(self,side_length):
        side_number= 6
        super().__init__(side_number,side_length)
    def Draw(self):
        d=self.Get_Side_Length()
        t = turtle.Turtle()
        for i in range(6):
            t.forward(d)
            t.right(60)
        
class Octagon(Polygon):
    def __init__(self,side_length):
        side_number=8
        super().__init__(side_number,side_length)
    def Draw(self):
        t = turtle.Turtle()
        d=self.Get_Side_Length()
        for i in range(8):
            t.forward(d)
            t.right(45)
class Quadrilateral(Polygon):
    def __init__(self,side_length):
        side_number = 4
        super().__init__(side_number,side_length)
    def Draw(self):
        t = turtle.Turtle()
        for counter in range(4):
            t.forward(self.__side_length)
            t.right(90)
class Rectangle(Quadrilateral):
    def __init__(self,Length, Width):
        self.__side_number = 4
        self.__Length = Length
        self.__Width = Width
    def Draw(self):
        t = turtle.Turtle()
        for counter in range(2) :
            t.forward(self.__Length)
            t.right(90)
            t.forward(self.__Width)
            t.right(90)
        
    def Perimeter(self) :
        print(f"The Perimeter =",((self.__Length+self.__Width)*2))
    def Area(self) :
        print(self.__Length*self.__Width)

class Square(Quadrilateral):
    def __init__(self,side_length):
        super().__init__(side_length)
    def Draw(self):
        super().Draw()
class Triangle(Polygon) :
    def __init__(self,side_length) :
        side_number=3
        super().__init__(side_number,side_length)
     #setter
    def Set_Side_Length(self, side_length):
        super().Set_Side_Length(side_length)
    #getter
    def Get_Side_Length(self) :
        return super().Get_Side_Length()
    def Area(self) :
        super().Area()
    def Perimeter(self) :
        super().Perimeter()
    def Pattern(self,side):
        i = 1
        while i<=side:
            print(" "*(side-i) + "* " * i)
            i+=1
    def Draw(self) :
        side=self.Get_Side_Length()
        self.Pattern(side)
class Equalateral_Triangle(Triangle) :
    def __init__(self, side_length):
        super().__init__(side_length)
    # setter
    def Set_Side_Length(self, side_length):
        super().Set_Side_Length(side_length)
    # getter
    def Get_Side_Length(self):
        return super().Get_Side_Length()
class Isosceles_Triangle(Triangle):
    istrue = 0
    def __init__(self, side,base):
           if (2*side)<=base:
               print("Wrong Sides")
           else :
               self.__side = side
               self.__base = base
               self.istrue =1
    # setter
    def Set_Sides(self,side,base):
        self.__side = side
        self.__base = base
    # getter
    def Get_Side_Length(self):
        return (self.__side,self.__base)
    def Area(self):
        S=(self.__base+self.__side+self.__side)/2
        print(math.sqrt(S*(S-self.__side)*(S-self.__side)*(S-self.__base)))
    def Perimeter(self):
        print(self.__base+2*self.__side)
    def Draw(self):
        height = math.sqrt((self.__side)*(self.__side)-0.5*(self.__base)*0.5*(self.__base))
        Img=np.zeros((500,500,3),dtype="uint8")
        triangle = np.array([[[250, 250], [250+(5*self.__base), 250+int(height*10)],  [250-(5*self.__base), 250+int(height*10)]]], np.int32)
        Img = cv2.polylines(Img, [triangle], True, (0,0,255), thickness=3)
        cv2.putText(Img,"Press 'q' to close the window",(50,400),cv2.FONT_HERSHEY_TRIPLEX,0.5,(255,255,255),1)
        cv2.imshow("Isosceles Triangle",Img)
        if cv2.waitKey(0) & 0xFF == ord('q') :
            cv2.destroyAllWindows()
def start() :
    print("""

    Choose a polygon from the menu :

    1 :Equalateral Triangle
    2 :Isosceles Triangle 
    3 :Square 
    4 :Rectangle 
    5 :Pentagon 
    6 :Hexagon 
    7 :Octagon 

    """)
    choice = int(input("Enter the Number of Polygon :"))
    if choice== 1 :
        print("You Choosed Equalateral Triangle ")
        side = int(input("Enter Side Length:"))
        triangle =Equalateral_Triangle(side)
        return triangle
    elif choice ==2 :
        print("You Choosed Isosceles Triangle ")
        base = int(input("Enter  Base length:"))
        side = int(input("Enter Side Length:"))
        triangle =Isosceles_Triangle(side,base)
        if triangle.istrue == 0 :
            return 0 
        return triangle
    elif choice == 3 :
        print("You Choosed Square ")
        side = int(input("Enter Side Length:"))
        Squ =Square(side)
        return Squ
    elif choice == 4 :
        print("You Choosed Rectangle ")
        Length = int(input("Enter Length:"))
        Width = int(input("Enter Width:"))
        Rect =Rectangle(Length,Width)
        return Rect
    elif choice ==5 :
        print("You Choosed Pentagon")
        side = int(input("Enter Side Length:"))
        Pent=Pentagon(side)
        return Pent
    elif choice ==6 :
        print("You Choosed Hexagon")
        side = int(input("Enter Side Length:"))
        Hex=Hexagon(side)
        return Hex

    elif choice ==7 :
        print("You Choosed Octagon")
        side = int(input("Enter Side Length:"))
        Oct=Octagon(side)
        return Oct   

def Operation(Class) :
    print("""
     Choose which to compute 
     1 : Area
     2 : Perimeter
     3 : Draw
    """)
    choice = int(input("Enter Operation No :"))
    if choice == 1 :
        Class.Area()
    if choice == 2 :
        Class.Perimeter()
    if choice ==3 :
        Class.Draw()
    print("""
      You want to Choose Another Polygon or Quit O.o 
     1 : Continue
     2 : Quit
    """)
    out = int(input("Enter your Choice No :"))
    if out == 1 :
        return True
    if out == 2 :
        return False    

def Check_Sides(Class) :
    if Class ==0 :
        print("You Choosed wrong sides for Isosceles Triangle")
        return 0
On = True
while On :
    while True :
        Class=start()
        if Check_Sides(Class) == 0 :
            break 
        if (Operation(Class)) :
            break
        else :
            On=False
            print("Bye Bye ")
            break
        


        
