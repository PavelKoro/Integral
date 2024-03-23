import ctypes
import matplotlib.pyplot as plt
import numpy as np

## Загрузка библиотеки с функциями
lib = ctypes.CDLL('./lagrange.so')

## Создаем экземпляр класса lagrange
lib.create_lagrange.restype = ctypes.c_void_p
lagrange_instance = lib.create_lagrange()

## Прототип функций
lib.y_x.restype = ctypes.c_double
lib.y_x.argtypes = [ctypes.c_void_p, ctypes.c_double]

lib.P.restype = ctypes.c_double
lib.P.argtypes = [ctypes.c_void_p, ctypes.c_double]

lib.P0.restype = ctypes.c_double
lib.P0.argtypes = [ctypes.c_void_p, ctypes.c_double]

lib.P1.restype = ctypes.c_double
lib.P1.argtypes = [ctypes.c_void_p, ctypes.c_double]

lib.P2.restype = ctypes.c_double
lib.P2.argtypes = [ctypes.c_void_p, ctypes.c_double]

lib.P3.restype = ctypes.c_double
lib.P3.argtypes = [ctypes.c_void_p, ctypes.c_double]

lib.P4.restype = ctypes.c_double
lib.P4.argtypes = [ctypes.c_void_p, ctypes.c_double]

## Создаем массив значений x
x = np.linspace(-0.5, 4.5, 100)

## Вычисляем значения y для каждого x
f_x = [lib.y_x(lagrange_instance, xi) for xi in x]
L = [lib.P(lagrange_instance, xi) for xi in x]
y0 = [lib.P0(lagrange_instance, xi) for xi in x]
y1 = [lib.P1(lagrange_instance, xi) for xi in x]
y2 = [lib.P2(lagrange_instance, xi) for xi in x]
y3 = [lib.P3(lagrange_instance, xi) for xi in x]
y4 = [lib.P4(lagrange_instance, xi) for xi in x]

## Преобразование списка в массив numpy для построения графика
f_x = np.array(f_x)
L = np.array(L)
y0 = np.array(y0)
y1 = np.array(y1)
y2 = np.array(y2)
y3 = np.array(y3)
y4 = np.array(y4)

## Строим график
plt.plot(x, f_x, label='(cosh(sqrt(x))-1)/x')
plt.plot(x, L, linestyle='dashed', label='P', color='wheat')
plt.plot(x, y0, label='P0', color='cyan')
plt.plot(x, y1, label='P1', color='orange')
plt.plot(x, y2, label='P2', color='green')
plt.plot(x, y3, label='P3', color='red')
plt.plot(x, y4, label='P4', color='purple')
plt.xlabel('x')
plt.ylabel('y')
plt.grid(True)
plt.legend()
plt.show()

## Освобождаем память, занимаемую экземпляром класса lagrange
lib.destroy_lagrange(lagrange_instance)