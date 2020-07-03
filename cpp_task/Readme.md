### Сборка
Что бы собрать проект:

```sh
cmake -H. -B_build
cmake --build _build
```

### Тесты
Что бы запустить тесты, после сборки проекта:
```sh
cmake --build _build --target test
```

Или
```sh
valgrind ./_build/check
```
### Пример использования
Бинарный файл примера использования, после сборки лежит
```sh
./_build/demo
```

рекомендуется использовать valgrind и перенаправлять стандартный ввод на ввод из файлов в папке inputDemo

Например

```sh
valgrind ./_build/demo < inputDemo/Romeo_and_Juliet_Shakespeare.txt

valgrind ./_build/demo < inputDemo/myInput.txt 
```

### Исходный код

В папке include лежит хедер библиотеки MyString

В папке sourses лежит исходник этой библиотеки

В папке examples лежит исходник примера использования библиотеки

В папке tests лежат тесты
