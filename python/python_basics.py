#!/usr/bin/env python

import re
import os
import sys
'''
String opreation

string
list
tuple
dictionary 
file
regular expressions
'''


def string_basic():
    address = 'prashant nagar, shikshak colony, kondapur, hyd 530002'
    print address
    print address.split()
    print len(address)
    print address[1]
    print address[len(address) - 10]

    print address[3:]
    print address[-3:]
    print address[10:33]

    print address[:19]
    print address[:-3]

    print address.islower()
    add = address.upper()
    print add

    print address.find('kondapur')

    if 'nagar' in address:
        print 'found'
    else:
        print 'not found'

    sub_address = '102 room, rangarao reddy house, 1st floor '
    contact_number = 32445345

    print sub_address + '\n' + address
    print sub_address + address + ' ' + str(contact_number)


# format specifier
    print 'Room number : %d , House name : %s , water bill : %.2f' % (
        102, 'Vinayaka', 4.55)

    room_number = '102'
    floor_numer = 299
    bill = '2.3345'

    print bill
    print float(bill) + 102

    if room_number == '102':
        print 'Expected room'

    if int(room_number) == 102:
        print 'Expexted room'

    if floor_numer < 10:
        print "Lift bill charges will increased by 0.6%"
    elif floor_numer == 20:
        print 'VIP room, no lift charges'
    else:
        print 'Please check with maintaince manger'


def list_basic(list_mates):
    member_list = []
    print list_mates
    print len(list_mates)
    print list_mates[1]
    print list_mates[-1:]
    print list_mates[3:]
    print list_mates[:4]
    print list_mates[3]
    print list_mates.index('sanjay')

    list_mates.append('rajesh')
    print list_mates
    list_mates.insert(3, 'VISHAL')
    print list_mates
    list_mates.remove('ajinath')
    print list_mates

    list_mates_hyd = ['SUMIT', 'prafull', 'nandya']
    list_mates_hyd.extend(list_mates)
    print list_mates_hyd

    if 'sumit' in list_mates_hyd:
        print 'Sumit lives in hyd'

    list_short_name = []
    list_long_name = []

    for name in list_mates_hyd:
        if len(name) > 5:
            list_long_name.append(name)

        if len(name) <= 5:
            list_short_name.append(name)

    print ' long names : ',  list_long_name
    print ' short names: ',  list_short_name

    # Sorting
    lsit_char = ['a', 'A', 'B', 'b']
    print sorted(lsit_char)
    print sorted(lsit_char, reverse=True)
    print sorted(lsit_char, key=len)
    print 'upper and lower'
    print sorted(lsit_char)
    print sorted(lsit_char, key=str.lower)

    list_int = [1, 44, 7, 9, 7676, 55, 898, 33]
    sum = 0
    for num in list_int:
        sum = sum + num
    print list_int
    print sum


def is_prime_num(num):
    isPrime = None
    if num > 1:
        for no in range(2, num):
            if (num % no) == 0 and num == no:
                isPrime = True
            elif (num % no) == 0 and num != 0:
                isPrime = False

    else:
        isPrime = True

    if isPrime:
        print str(num) + ' is a prime num'
    else:
        print str(num) + ' is not a prime num'


def tuple_basic():
    tpl_home = ['iron', 3, 'Wash', 5.99, 'C']
    print tpl_home

    list_str = []
    list_num = []

    for mem in tpl_home:
        print mem
        if type(mem) == str:
            list_str.append(mem)
        elif type(mem) == int or type(mem) == float:
            list_num.append(mem)

    print list_num
    print list_str


def dict_basic():
    dict_mob = {
        'shinu': '98789977',
        'sumit': '7866778',
        'ajinath': '986058499',
    }
    print dict_mob
    print len(dict_mob)
    print dict_mob.has_key('sanjay')

    for key in dict_mob:
        if key.startswith('s'):
            print key + ' is from S family'

    dict_square = {}
    for num in range(0, 100):
        dict_square[num] = num * num

    print dict_square

    print " Square of 4 :" + str(dict_square[4])

    print dict_mob
    print sorted(dict_mob)

    for key, val in dict_mob.items():
        print '-' * 90
        print key
        print val
        print '-' * 90


def file_basic():
    try:
        file_content = open('test.txt', 'r')
    except IOError:
        print 'file opened failed'

    try:
        file_filtered = open('filtered.txt', 'w')
    except IOError:
        print 'filtered file create failed'

    for line in file_content:
        list_words = line.split()
        if 'BroadcastQueue:' in list_words:
            file_filtered.write(line)

    name = 'shriNivaS PATil'
    tmp_name = name.lower()
    print tmp_name

    list_char = list(tmp_name)
    print list_char
    list_char[0] = list_char[0].upper()
    print list_char

    final_name = ''.join(list_char)
    print final_name


def re_exp_basic():
    try:
        file_content = open('test.txt', 'r')
    except IOError:
        print 'file opened failed'

    print ' Opening file : ' + os.path.abspath('test.txt')
    try:
        file_filtered = open('filtered.txt', 'w')
    except IOError:
        print 'filtered file create failed'

    for line in file_content:
        match = re.search(r'Broadcast', line)
        if match:
            #print match.group()
            file_filtered.write(line)

    str = 'sringu asdlk klfjwep0 safajd fajs fas shinu@gmail.com al;sdjf aldfal;sfjasf'
    print str
    match = re.search(r'[\w.-]+@[\w.-]+', str)
    if match:
        print match.group()  # 'alice-b@google.com'

    try:
        file_content = open('test.txt', 'r')
    except IOError:
        print 'file opened failed'

    strings = re.findall(r'shinu', file_content.read())
    print strings


def main():
    # print 'this is main function '
    # string_basic()
    # list_roomates = ['shinu','ajinath','nilesh','sanjay'    if os.path.
    # list_basic(list_roomates)
    # tuple_basic()
    # dict_basic()
    # file_basic()
    re_exp_basic()


if __name__ == '__main__':
    main()
