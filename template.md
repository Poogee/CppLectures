# Template

## Function template

```cpp
int max(int a, int b)
{
    return (a >= b ? a : b);
}

//...

int main()
{
    const int a = 3, b = 2, c = 1;

    const int abMaxInt = max(a, b);
    const int maxInt = max(abMaxInt, c);

    return 0;
}
```

<iframe width="1000px" height="600px" src="https://godbolt.org/e#g:!((g:!((g:!((h:codeEditor,i:(filename:'1',fontScale:14,fontUsePx:'0',j:1,lang:c%2B%2B,selection:(endColumn:2,endLineNumber:16,positionColumn:2,positionLineNumber:16,selectionStartColumn:2,selectionStartLineNumber:16,startColumn:2,startLineNumber:16),source:'int+max(int+a,+int+b)%0A%7B%0A++++return+(a+%3E%3D+b+%3F+a+:+b)%3B%0A%7D%0A%0A//...%0A%0Aint+main()%0A%7B%0A++++const+int+a+%3D+3,+b+%3D+2,+c+%3D+1%3B%0A%0A++++const+int+abMaxInt+%3D+max(a,+b)%3B%0A++++const+int+maxInt+%3D+max(abMaxInt,+c)%3B%0A%0A++++return+0%3B%0A%7D'),l:'5',n:'1',o:'C%2B%2B+source+%231',t:'0')),k:50.51298579217362,l:'4',n:'0',o:'',s:0,t:'0'),(g:!((h:executor,i:(argsPanelShown:'1',compilationPanelShown:'0',compiler:g141,compilerName:'',compilerOutShown:'0',execArgs:'',execStdin:'',fontScale:14,fontUsePx:'0',j:1,lang:c%2B%2B,libs:!(),options:'-std%3Dc%2B%2B17',overrides:!(),runtimeTools:!(),source:1,stdinPanelShown:'1',wrap:'1'),l:'5',n:'0',o:'Executor+x86-64+gcc+14.1+(C%2B%2B,+Editor+%231)',t:'0')),k:49.48701420782639,l:'4',n:'0',o:'',s:0,t:'0')),l:'2',n:'0',o:'',t:'0')),version:4"></iframe>

<br><br><br><br><br><br><br><br><br><br><br><br>

```cpp
char max(char a, char b)
{
    return (a >= b ? a : b);
}

unsigned char max(unsigned char a, unsigned char b)
{
    return (a >= b ? a : b);
}

short int max(short int a, short int b)
{
    return (a >= b ? a : b);
}

unsigned short int max(unsigned short int a, unsigned short int b)
{
    return (a >= b ? a : b);
}

int max(int a, int b)
{
    return (a >= b ? a : b);
}

unsigned int max(unsigned int a, unsigned int b)
{
    return (a >= b ? a : b);
}

int main()
{
    const int a = 3, b = 2, c = 1;
    const int abMaxInt = max(a, b);
    const int maxInt = max(abMaxInt, c);
  
    const char aChar = 'c', bChar = 'b', cChar = 'a';
    const char abMaxChar = max(aChar, bChar);
    const char maxChar = max(abMaxChar, cChar);

    return 0;
}
```

<br><br><br><br><br><br><br><br><br><br><br><br>

```cpp
template<typename Type> /* template<class Type> */
Type max(Type a, Type b)
{
    return (a >= b ? a : b);
}

int main()
{
  // Использование шаблона "max<Type>(Type, Type)" с подстановкой "int"
    const int a = 3, b = 2, c = 1;
    const int abMax = max<int>(a, b);
    const int maxInt = max<int>(abMax, c);

  // Использование того же шаблона max<Type>(Type, Type) с подстановкой "char"  
    const char aChar = 3, bChar = 2, cChar = 1;
    const char abMaxChar = max<char>(aChar, bChar);
    const char maxChar = max<char>(abMaxChar, cChar);  
  
    return 0;
}
```

<br><br><br><br><br><br><br><br><br><br><br><br>

```cpp
int max<int>(int a, int b)
{
    return (a >= b ? a : b);
}
char max<char>(char a, char b)
{
    return (a >= b ? a : b);
}

int main()
{
    const int a = 3, b = 2, c = 1;
    const int abMax = max<int>(a, b);
    const int maxInt = max<int>(abMax, c);

    const char aChar = 3, bChar = 2, cChar = 1;
    const char abMaxChar = max<char>(aChar, bChar);
    const char maxChar = max<char>(abMaxChar, cChar);  
  
    return 0;
}
```

<br><br><br><br><br><br><br><br><br><br><br><br>

## Template type deduction

```cpp
template<typename Type>
Type max(Type a, Type b)
{
    return (a >= b ? a : b);
}

int main()
{
    const int a = 3, b = 2, c = 1;
    const int abMax = max(a, b); /* max<int> */
    const int maxInt = max(abMax, c); /* max<int> */

    const char aChar = 3, bChar = 2, cChar = 1; 
    const char abMaxChar = max(aChar, bChar); /* max<char> */
    const char maxChar = max(abMaxChar, cChar); /* max<char> */

    const int abCharMax = max(a, bChar);
  
    return 0;
}
```

<iframe width="1000px" height="400px" src="https://godbolt.org/e#g:!((g:!((g:!((h:codeEditor,i:(filename:'1',fontScale:14,fontUsePx:'0',j:1,lang:c%2B%2B,selection:(endColumn:12,endLineNumber:9,positionColumn:12,positionLineNumber:9,selectionStartColumn:12,selectionStartLineNumber:9,startColumn:12,startLineNumber:9),source:'template%3Ctypename+Type%3E%0AType+max(Type+a,+Type+b)%0A%7B%0A++++return+(a+%3E%3D+b+%3F+a+:+b)%3B%0A%7D%0A%0Aint+main()%0A%7B%0A++++const+int+a+%3D+3,+b+%3D+2,+c+%3D+1%3B%0A++++const+int+abMax+%3D+max(a,+b)%3B+/*+max%3Cint%3E+*/%0A++++const+int+maxInt+%3D+max(abMax,+c)%3B+/*+max%3Cint%3E+*/%0A%0A++++const+char+aChar+%3D+3,+bChar+%3D+2,+cChar+%3D+1%3B+%0A++++const+char+abMaxChar+%3D+max(aChar,+bChar)%3B+/*+max%3Cchar%3E+*/%0A++++const+char+maxChar+%3D+max(abMaxChar,+cChar)%3B+/*+max%3Cchar%3E+*/%0A%0A++++const+int+abCharMax+%3D+max(a,+bChar)%0A++%0A++++return+0%3B%0A%7D'),l:'5',n:'1',o:'C%2B%2B+source+%231',t:'0')),k:50,l:'4',n:'0',o:'',s:0,t:'0'),(g:!((g:!((h:output,i:(compilerName:'x86-64+gcc+14.1',editorid:1,fontScale:14,fontUsePx:'0',j:1,wrap:'1'),l:'5',n:'0',o:'Output+of+x86-64+gcc+14.1+(Compiler+%231)',t:'0')),header:(),l:'4',m:50,n:'0',o:'',s:0,t:'0'),(g:!((h:compiler,i:(compiler:g141,filters:(b:'0',binary:'1',binaryObject:'1',commentOnly:'0',debugCalls:'1',demangle:'0',directives:'0',execute:'1',intel:'0',libraryCode:'0',trim:'1',verboseDemangling:'0'),flagsViewOpen:'1',fontScale:14,fontUsePx:'0',j:1,lang:c%2B%2B,libs:!(),options:'',overrides:!(),selection:(endColumn:90,endLineNumber:4,positionColumn:90,positionLineNumber:4,selectionStartColumn:90,selectionStartLineNumber:4,startColumn:90,startLineNumber:4),source:1),l:'5',n:'0',o:'+x86-64+gcc+14.1+(Editor+%231)',t:'0')),header:(),k:50,l:'4',m:50,n:'0',o:'',s:0,t:'0')),k:50,l:'3',n:'0',o:'',t:'0')),l:'2',n:'0',o:'',t:'0')),version:4"></iframe>

<br><br><br><br><br><br><br><br><br><br><br><br>

## Шаблоны класса

```cpp
template<typename Type>
class Interval
{
public:
  Interval(Type inStart, Type inEnd)
    : start(inStart), end(inEnd)
  {
  }

  Type getStart() const
  {
    return start;
  }

  Type getEnd() const
  {
    return end;
  }

  Type getSize() const
  {
    return (end - start);
  }

  // Метод для получения интервала пересечения данного интервала с другим
  Interval<Type> intersection(const Interval<Type>& inOther) const
  {
    return Interval<Type>{
        std::max(start, inOther.start),
        std::min(end, inOther.end)
    };
  }

private:
  Type start;
  Type end;
};
```

<br><br><br><br><br><br><br><br><br><br><br><br>

### Ремарка

```cpp
#include <vector>
#include <iostream>

template <typename Type>
void PrintVector(const std::vector<Type>& vec)
{
  for(const Type& value : vec) {
    std::cout << value << " ";
  }
  std::cout << "\n";
}

int main()
{
    std::vector /*<int>*/ x = {3,2,1};
    std::vector y = {std::string{"hello "}, std::string{"world!"}};
    PrintVector(x);
    PrintVector(y);
}
```

<iframe width="1000px" height="400px" src="https://godbolt.org/e#g:!((g:!((g:!((h:codeEditor,i:(filename:'1',fontScale:14,fontUsePx:'0',j:1,lang:c%2B%2B,selection:(endColumn:1,endLineNumber:12,positionColumn:1,positionLineNumber:12,selectionStartColumn:1,selectionStartLineNumber:12,startColumn:1,startLineNumber:12),source:'%23include+%3Cvector%3E%0A%23include+%3Ciostream%3E%0A%0Atemplate+%3Ctypename+Type%3E%0Avoid+PrintVector(const+std::vector%3CType%3E%26+vec)%0A%7B%0A++for(const+Type%26+value+:+vec)+%7B%0A++++std::cout+%3C%3C+value+%3C%3C+%22+%22%3B%0A++%7D%0A++std::cout+%3C%3C+%22%5Cn%22%3B%0A%7D%0A%0Aint+main()%0A%7B%0A++++std::vector+/*%3Cint%3E*/+x+%3D+%7B3,2,1%7D%3B%0A++++std::vector+y+%3D+%7Bstd::string%7B%22hello+%22%7D,+std::string%7B%22world!!%22%7D%7D%3B%0A++++PrintVector(x)%3B%0A++++PrintVector(y)%3B%0A%7D'),l:'5',n:'1',o:'C%2B%2B+source+%231',t:'0')),k:50,l:'4',n:'0',o:'',s:0,t:'0'),(g:!((h:executor,i:(argsPanelShown:'1',compilationPanelShown:'0',compiler:g141,compilerName:'',compilerOutShown:'0',execArgs:'',execStdin:'',fontScale:14,fontUsePx:'0',j:1,lang:c%2B%2B,libs:!(),options:'',source:1,stdinPanelShown:'1',wrap:'1'),l:'5',n:'0',o:'Executor+x86-64+gcc+14.1+(C%2B%2B,+Editor+%231)',t:'0')),header:(),k:50,l:'4',n:'0',o:'',s:0,t:'0')),l:'2',n:'0',o:'',t:'0')),version:4"></iframe>

<br><br><br><br><br><br><br><br><br><br><br><br>

## Специализация

```cpp
template<typename T> // primary template
struct is_void {
  static const bool value = false;
};
template<>           // explicit specialization for T = void
struct is_void<void> {
  static const bool value = true;
};
```

<iframe width="1000px" height="400px" src="https://godbolt.org/e#g:!((g:!((g:!((h:codeEditor,i:(filename:'1',fontScale:14,fontUsePx:'0',j:1,lang:c%2B%2B,selection:(endColumn:2,endLineNumber:13,positionColumn:2,positionLineNumber:13,selectionStartColumn:2,selectionStartLineNumber:13,startColumn:2,startLineNumber:13),source:'template%3Ctypename+T%3E+//+primary+template%0Astruct+is_void+%7B%0A++static+const+bool+value+%3D+false%3B%0A%7D%3B%0Atemplate%3C%3E+++++++++++//+explicit+specialization+for+T+%3D+void%0Astruct+is_void%3Cvoid%3E+%7B%0A++static+const+bool+value+%3D+true%3B%0A%7D%3B%0A%0Aint+main()+%7B%0A++++static_assert(is_void%3Cvoid%3E::value)%3B%0A++++static_assert(is_void%3Cint%3E::value)%3B%0A%7D'),l:'5',n:'1',o:'C%2B%2B+source+%231',t:'0')),k:50,l:'4',n:'0',o:'',s:0,t:'0'),(g:!((h:executor,i:(argsPanelShown:'1',compilationPanelShown:'0',compiler:g141,compilerName:'',compilerOutShown:'0',execArgs:'',execStdin:'',fontScale:14,fontUsePx:'0',j:1,lang:c%2B%2B,libs:!(),options:'',source:1,stdinPanelShown:'1',wrap:'1'),l:'5',n:'0',o:'Executor+x86-64+gcc+14.1+(C%2B%2B,+Editor+%231)',t:'0')),header:(),k:50,l:'4',n:'0',o:'',s:0,t:'0')),l:'2',n:'0',o:'',t:'0')),version:4"></iframe>

<br><br><br><br><br><br><br><br><br><br><br><br>

## Шаблоны-аргументы

```cpp
#include <iostream>

template<size_t Value>
size_t getFactorial()
{
    return Value * getFactorial<Value - 1>();
}

template<>
size_t getFactorial<0>()
{
    return 1;
}

int main()
{
    std::cout << getFactorial<10>();
}
```

<br><br><br><br><br><br><br><br><br><br><br><br>

## Частичная специализация

<iframe width="1000px" height="600px" src="https://godbolt.org/e#z:OYLghAFBqd5QCxAYwPYBMCmBRdBLAF1QCcAaPECAMzwBtMA7AQwFtMQByARg9KtQYEAysib0QXACx8BBAKoBnTAAUAHpwAMvAFYTStJg1DIApACYAQuYukl9ZATwDKjdAGFUtAK4sGIAGykrgAyeAyYAHI%2BAEaYxBIAzKQADqgKhE4MHt6%2BASlpGQKh4VEssfFcSXaYDplCBEzEBNk%2BfoHVtQL1jQTFkTFxibYNTS257SO9Yf1lg5UAlLaoXsTI7BzmCWHI3lgA1CYJbk4KBMSYrIfYBxoAgnsPJncA9M8HACJcJgAc3ybvGhMFkBAKBX1BFisEOw/0BFneHzht1hQKhcJBX2%2B4Mx4PRT1uBEwLGSBkJByOBAAnslGKxMHsACqkPZUmnMNh7ADSV3xOyYCgUe2UcQUAgOAHYrHdkl5orQ8MgQPiHg9hcRRQwIKd0CAQKdiGFgHt2ZhmZy9skEAJMPM9iBjXSTJKTU73szLdanRYPeFXcqVV6Je9/Q8AG6oPDoPZKAgASXQEAZe1DYi8NolFj2kfJCJT3kwhys4uDdxVyYjUeSBsEEFtaAYpxDGabZe1urQXgI5LchzcBzMZnj9vMZm7vazUd745HJgArG4CBE6cOB2Ojg6OVP1zP5wRlFbwivR1u%2Bz76SfowQdSBXLRC02/dKDSnCUrSyqk5H7%2B%2BHm29WdDQ3AsEile4VXNM9v2RYsoJuW5Xg%2BTFxRRYF/hxNCfjMFC/k%2BH5kIhYMIQxH4ADFEJ%2BXEgRIlDZww75/GwlCQThNEgRwuF8LxXD6MY7iyLo9igWYsEUNYiwYQIpjESBSRRLo/juKwiFBIsaiiL2LwGzwYBwnQfFCWJUlzwpalaQ5bkEhhO4%2BQFIURQEXtNPSHTMHQM0rmbaVZXlRUmzVDUtSvXV9UAk0zQtA903tF1nUdYt3Uir1IJgn8Mzgssy2zQ4EWsawO0EWCAxSsCwwrC1qwIWs9nrRtUq9FsVT/DsuwvEch37Y8jnHLKuu3Ac5wXJc2CPNc%2BxNUaOoGvdIpGi8zwmv9b0Kx5iqrPAX3YJtTiYRxkCzBh5XCDStJcqN8oIeqYJApsnO03SJ2Wy9rxCowgMeiDEuuu4/S%2B%2B58TCLsWCYMJa3xerUv8hyjj/F7gGZGGAKMDzolQaJ6oHCxUZHZkZ0sLgzASSRZ38cV/F%2BGcrszFUEKTABaJ7gsR4AmxR6IADoY3jCAR0qEd5ke1m2bWmt%2BZAssEPayoHiG9g9kx6IMtVGb%2BwsfHCeJ0nydLPz7IYRyTt0%2BGgv/atmcsllUBYdGzAZS3scmyxJCd52XYp4NfrLIgWCFirQbF6m3kllUZftW2WEVoVlesF2Y9k7WId1/XnMNhmTcNDyFEuSURyES4Bxx/rLFnYuS5Lt3Hsz73hcq0WqYeCWdT2UdpeXPZc/DxX92tFcLFLvuweLDhFloThZ14PxuF4VBOB7SxrGjZZVnPAmeFIAhNCHxYAGsQFnDR9E4SRx430hp44XgFBAff144LRFjgWAkEwVQak7EhyEoRpgAUZRDEwWghBWgAO4T1XmgYkdAdqZF/uEABwCJ5aFIOA5IdBBjACkFwJBlsUH0GICHc%2BWCIG4IAPKdkAagEBJ9n41FuMQb%2BnBeDUOQPUfAE9eD8EECIMQ7ApAyEEIoFQ6hb46D0AYIwKBcqWH0HgaIl9ICLFQMkRwAhL4ENFCsNYehtRhBgf/chlDJ6kCAcQJgyROA8GHqPY%2BwjT6cGwC/ZAb9iB7FUPRWm/hJB7GAMgPaUg2ZcD2BAWeVgpF7FwIQEg/YEhcHmLwG%2Bd9FgIAuFgeItZSA7z3gfDgR9SAIKngw2wV814b3mJYjgZhrGILPnEkpixQwikyCASQQA%3D"></iframe>

## Пример + Паттерн

Проблема:

<https://github.com/search?q=repo%3Anook0110%2FSimple+static_cast&type=code>

```cpp

template <class UnderlyingType, size_t size, class EnumType>
class EnumArray : public std::array<UnderlyingType, size> {
public:
  std::array<UnderlyingType, size>::reference operator[](EnumType pos) {
    return std::array<UnderlyingType, size>::operator[](
        static_cast<size_t>(pos));
  }

  std::array<UnderlyingType, size>::const_reference
  operator[](EnumType pos) const {
    return std::array<UnderlyingType, size>::operator[](
        static_cast<size_t>(pos));
  }
};
```
<iframe width="1000px" height="400px" src="https://godbolt.org/e#g:!((g:!((g:!((h:codeEditor,i:(filename:'1',fontScale:14,fontUsePx:'0',j:1,lang:c%2B%2B,selection:(endColumn:23,endLineNumber:26,positionColumn:23,positionLineNumber:26,selectionStartColumn:23,selectionStartLineNumber:26,startColumn:23,startLineNumber:26),source:'%23include+%3Carray%3E%0A%23include+%3Ccstddef%3E%0A%0Atemplate+%3Cclass+UnderlyingType,+size_t+size,+class+EnumType%3E%0Aclass+EnumArray+:+public+std::array%3CUnderlyingType,+size%3E+%7B%0Apublic:%0A++typename+std::array%3CUnderlyingType,+size%3E::reference+operator%5B%5D(EnumType+pos)+%7B%0A++++return+std::array%3CUnderlyingType,+size%3E::operator%5B%5D(%0A++++++++static_cast%3Csize_t%3E(pos))%3B%0A++%7D%0A%0A++typename+std::array%3CUnderlyingType,+size%3E::const_reference%0A++operator%5B%5D(EnumType+pos)+const+%7B%0A++++return+std::array%3CUnderlyingType,+size%3E::operator%5B%5D(%0A++++++++static_cast%3Csize_t%3E(pos))%3B%0A++%7D%0A%7D%3B%0A%0Aint+main()+%7B%0A++enum+class+test+%7B+A,+B+%7D%3B%0A%0A++EnumArray%3Cint,+2,+test%3E+en_arr+%3D+%7B3,+5%7D%3B%0A++std::array%3Cint,+2%3E+arr+%3D+%7B3,+5%7D%3B%0A++en_arr%5Btest::A%5D+%3D+2%3B%0A++//+en_arr%5B0%5D+%3D+0%3B%0A++//+arr%5Btest::A%5D+%3D+2%3B%0A++arr%5B0%5D+%3D+0%3B%0A%7D'),l:'5',n:'1',o:'C%2B%2B+source+%231',t:'0')),k:50.51298579217362,l:'4',n:'0',o:'',s:0,t:'0'),(g:!((h:executor,i:(argsPanelShown:'1',compilationPanelShown:'0',compiler:g141,compilerName:'',compilerOutShown:'0',execArgs:'',execStdin:'',fontScale:14,fontUsePx:'0',j:1,lang:c%2B%2B,libs:!(),options:'-std%3Dc%2B%2B17',overrides:!(),runtimeTools:!(),source:1,stdinPanelShown:'1',wrap:'1'),l:'5',n:'0',o:'Executor+x86-64+gcc+14.1+(C%2B%2B,+Editor+%231)',t:'0')),k:49.48701420782639,l:'4',n:'0',o:'',s:0,t:'0')),l:'2',n:'0',o:'',t:'0')),version:4"></iframe>
