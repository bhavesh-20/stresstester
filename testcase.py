import sys
import os
import random

sys.stdout = open("testcase.txt", "w")


class RandomGenerator():
    def __init__(self):
        pass

    def integer(self, lower_bound, upper_bound):
        ret = random.randint(lower_bound, upper_bound)
        return ret

    def array(self, array_size, lower_bound, upper_bound):
        l = [0]*array_size
        for index, element in enumerate(l):
            l[index] = self.integer(lower_bound, upper_bound)
        return l


class ListOperation():
    def __init__(self):
        pass

    def print_space(self, l):
        for element in l:
            print(element, end=" ")
        print()

    def print_csv(self, l):
        for element in l:
            print(element, end=", ")
        print()


class Print():
    def __init__(self):
        pass

    def inline_print(self, n):
        """
        print n elements in a line and then print an endline
        """
        for i in range(n):
            print()


if __name__ == "__main__":
    t=100
    #print(t)
    print(str(t)+"\n",end="")
    for _ in range(t):
        n=random.randint(1,10)
        print(str(n)+"\n",end="")
        #print(n)
        s=set()
        i=0
        a=[]
        while i<n:
            x=random.randint(1,30);
            if x in s:
                i-=1
            else:
                a.append(x)
                s.add(x)
            i+=1
        if 1 not in s:
            rand_index=random.randint(0,n-1)
            a[rand_index]=1
        for i in a:
            print(str(i)+" ",end="")
        print("\n",end="")
        q=random.randint(5,35)
        print(str(q)+"\n",end="")
        i=0
        se=set()
        while i<q:
            x=random.randint(1,35)
            if x in se:
                i-=1
            else:
                print(str(x)+" ",end="")
                se.add(x)
            i+=1
        print("\n",end="")