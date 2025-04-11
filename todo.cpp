#include "todo.h"
#include <stdexcept>

void TodoList::init() {
    size = 0;
    for (char *&task: tasks) {
        task = nullptr;
    }
    // TODO: set size to 0 and all task pointers to nullptr
}

void TodoList::destroy() {
    for (char *&task: tasks) {
        delete task;
        task = nullptr;
    }
    size = 0;
    // TODO: delete all tasks and reset pointers
}

int TodoList::string_length(const char *str) const {
    int i = 0;
    while (true) {
        if (str[i] == '\0') {
            break;
        }
        i += 1;
    }
    return i;
    // TODO: return the number of characters before '\0'
}

void TodoList::string_copy(char *dest, const char *src) const {
    int size = string_length(src);

    for (int i = 0; i < size; i++) {
        dest[i] = src[i];
    }
    dest[size] = '\0';
    // TODO: copy characters from src to dest
}

void TodoList::add_task(const char *task) {
    if (size == MAX_TASKS) {
        throw std::length_error("full tasks");
    }

    tasks[size] = new char[string_length(task) + 1];
    string_copy(tasks[size], task);
    size += 1;
    // TODO: if full, throw. otherwise allocate and copy new task
}

// A
// B
// C
//
// index=1

void TodoList::remove_task(int index) {
    for (int i = index + 1; i < size; i++) {
        delete[] tasks[i - 1];
        tasks[i - 1] = new char[string_length(tasks[i]) + 1];

        string_copy(tasks[i - 1], tasks[i]);
    }
    if (tasks[size - 1] != nullptr) {
        delete[] tasks[size - 1];
        tasks[size - 1] = nullptr;
    }
    size -= 1;
    // TODO: check bounds, delete task, shift left
}

const char **TodoList::get_pending_tasks(int &count) const {
    count = size;

    char **copied_tasks = new char *[size];
    for (int i = 0; i < size; i++) {
        copied_tasks[i] = new char[string_length(tasks[i]) + 1];
        string_copy(copied_tasks[i], tasks[i]);
    }

    return const_cast<const char **>(copied_tasks);
}