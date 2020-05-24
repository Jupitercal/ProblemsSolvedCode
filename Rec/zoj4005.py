# -*- coding: utf-8 -*-
"""
Created on Mon Mar 12 20:01:15 2018

@author: LL
"""

def sqrt(n):
    l=0
    r=n
    while (l<=r) :
        mid=(l+r)//2;
        F=mid*mid
        if (F>n): r=mid-1
        elif (F<n): l=mid+1
        else :return mid
    return l-1


T=int(input())
for i in range(0,T):
    a=int(input())
    a=sqrt(a)
    print(a&1)