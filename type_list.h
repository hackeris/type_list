//
// Created by rainm on 2017/8/9.
//

#ifndef TYPELIST_TYPE_LIST_H
#define TYPELIST_TYPE_LIST_H

struct empty_type_list {
};

template<typename T, typename U>
struct type_list {
    using head = T;
    using tail = U;
};

template<typename...>
struct make_type_list;

template<>
struct make_type_list<> {
    using result = empty_type_list;
};

template<typename T, typename ...types>
struct make_type_list<T, types...> {
    using tail = typename make_type_list<types...>::result;
    using result = type_list<T, tail>;
};

template<typename>
struct length_of;

template<>
struct length_of<empty_type_list> {
    static constexpr int value = 0;
};

template<typename head, typename tail>
struct length_of<type_list<head, tail>> {
    static constexpr int value = length_of<tail>::value + 1;
};

template<typename, typename>
struct index_of;

template<typename T>
struct index_of<empty_type_list, T> {
    static constexpr int value = -1;
};

template<typename T, typename tail>
struct index_of<type_list<T, tail>, T> {
    static constexpr int value = 0;
};

template<typename head, typename tail, typename T>
struct index_of<type_list<head, tail>, T> {
    using index_in_tail = index_of<tail, T>;
    static constexpr int value = (index_in_tail::value == -1) ? -1 : index_in_tail::value + 1;
};

template<typename list, typename T>
struct contains {
    static constexpr bool value = index_of<list, T>::value >= 0;
};

#endif //TYPELIST_TYPE_LIST_H
