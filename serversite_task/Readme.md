[![Build Status](https://travis-ci.com/nevstruevdmitriy/NevstruevDmitriy_targem.svg?branch=master)](https://travis-ci.com/nevstruevdmitriy/NevstruevDmitriy_targem)

## Сборка
Что бы собрать проект:
```sh
cmake -H. -B_build
cmake --build _build
```

## Запуск
```sh
./_build/app
```

## Особенности

Использую фреймворки libcurl для получения коммитов, nlohmann/json для того чтобы распарсить json.

Вывожу результат в стандартный поток вывода, не сортирую ни по дате ни по имени автора. Дату вывожу в формате ISO8601
