'''
Builder模式
将一个复杂对象的构建与他的表示分离，使得同样的构建过程可以创建不同的表示。

用统一的接口完成同一类功能不同类型的实现与构建

基本思想：
# 某类产品的构建由很多复杂组件组成；
# 这些组件中的某些细节不同，构建出的产品表象会略有不同；
# 通过一个指挥者按照产品的创建步骤来一步步执行产品的创建；
# 当需要创建不同的产品时，只需要派生一个具体的建造者，重写相应的组件构建方法即可

类似于车辆生产: 车辆类别不同，

由Director根据订单需求产生建造者并让该制造者完成订单需求
对于用户来说，订单产品专员是固定的，制造者由产品专员自己联系相应制造者完成
'''

import abc

# 车辆基类 （产品基类） 属性不同产生产品不同，由不同制造者制造
class Vehicle(object):

    def __init__(self, type_name):
        self.type = type_name
        self.wheels = None
        self.doors = None
        self.seats = None

    # 不同的车子类型，齿轮，车门数，座位数都不尽相同
    def view(self):
        print(
            "This vehicle is a " +
            self.type +
            " with; " +
            str(self.wheels) +
            " wheels, " +
            str(self.doors) +
            " doors, and " +
            str(self.seats) +
            " seats."
        )

# 构建建造者基类，抽象建造者的共有属性
class VehicleBuilder(metaclass=abc.ABCMeta):

    # 装饰器定义抽象方法（只能用在 metaclass 为 abc.ABCMeta 或其子类的 class 中）
    # 这里其实当然可以用pass，或者raise一个基类未实现的异常
    @abc.abstractmethod
    def make_wheels(self):
        raise

    @abc.abstractmethod
    def make_doors(self):
        raise

    @abc.abstractmethod
    def make_seats(self):
        raise


# 汽车建造者
class CarBuilder(VehicleBuilder):

    def __init__(self):
        self.vehicle = Vehicle("Car ")

    def make_wheels(self):
        self.vehicle.wheels = 4

    def make_doors(self):
        self.vehicle.doors = 3

    def make_seats(self):
        self.vehicle.seats = 5


# 自行车建造者
class BikeBuilder(VehicleBuilder):

    def __init__(self):
        self.vehicle = Vehicle("Bike")

    def make_wheels(self):
        self.vehicle.wheels = 2

    def make_doors(self):
        self.vehicle.doors = 0

    def make_seats(self):
        self.vehicle.seats = 2

# 制造的Director，用于接受用户订单，分配给相应制造者
class VehicleManufacturer(object):

    def __init__(self):
        self.builder = None # 分配相应制造者

    # 根据传进来的builder制造它提供的产品规格
    def create(self):
        # 制造者调用自己的方法实现产品构建
        assert not self.builder is None, "No defined builder"
        self.builder.make_wheels()
        self.builder.make_doors()
        self.builder.make_seats()
        return self.builder.vehicle

if __name__ == "__main__":
    # 整个过程都是在VehicleManufacturer完成
    # 指引者发送对应产品的订单给相应建造者

    print('='*10 + "Example 1: car" + '='*10)
    manufacturer = VehicleManufacturer() # 产生指引者
    # 重要的是这样的调用方式，每次修改builder方法传入不同的要求，然后在create里面去制造，

    manufacturer.builder = CarBuilder()
    # 建造者制造
    car = manufacturer.create()
    # 查看产品
    car.view()

    print('=' * 10 + "Example 2: bike" + '=' * 10)
    manufacturer.builder = BikeBuilder()
    bike = manufacturer.create()
    bike.view()