# Assignment #3. Data structures

# Варіант #0. Обчислення арифметичного виразу.

Обчислити результат математичного виразу, що подається на вхід програми через аргументи командного рядка (будь ласка, уважно ще раз перечитайте останнє речення: не через файл і не через ввід у самій програмі). Наприклад, якщо ваша програма компілюється у файл calc.exe, вона має запускатися через командний рядок так:

> calc.exe 1 + 2 * 4+1 [Enter]
> Result: 10

Зверніть увагу, що в деяких місцях є пробіли, в деяких вони відсутні.
Перевіряти введені дані на правильність та будувати синтаксичне дерево (AST) в цьому варіанті не обов'язково!

Для вирішення задачі треба реалізувати алгоритм сортувальної станції, що дозволяє обчислювати значення введеного арифметичного виразу. Стандартний спосіб зробити сортувальну станцію – використувати два стеки. Структуру стек необхідно написати власноруч.

Складніше завдання (+1 бал): Додати обробку від'ємних чисел, дужок та степенів (також без перевірки на правильність вводу).
