'''
注册器模式：

对于函数接口需要非常多的输入参数，且函数功能分离，接口统一的情况下可以使用

常用来替代工厂模式中的switch语句

原理是生成全局字典，保留函数功能，也可以任意添加功能，在运行时根据函数接口定义的功能进行选择
'''



class RegisterMachine:

    def __init__(self, name):
        # name of register
        self._name = name
        self._name_method_map = dict()


    def register(self, func=None):
        # obj == None for function call register
        # otherwise for decorator way

        if func != None:
            name = func.__name__
            self._name_method_map[name] = func
        else:
            def wrapper(func):
                name = func.__name__
                self._name_method_map[name] = func

                return func

            return wrapper

    def get(self, name):
        return self._name_method_map[name]


def say_hi_with(name):
        print("Hi, {person}!".format(person=name))

if __name__ == "__main__":
    # 注册器类
    register_obj = RegisterMachine("register")

    # 为不同功能接口添加注册器 使用装饰器 register
    @register_obj.register 
    def say_hello_with(name):
        print("Hello, {person}!".format(person=name))

    register_obj.get("say_hello_with")("Peter")
    
    # function call metho d
    register_obj.register(say_hi_with)
    register_obj.get("say_hi_with")("John")