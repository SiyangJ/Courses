<TeXmacs|1.99.4>

<style|generic>

<\body>
  <center|COMP550 Assignment 4>

  <center|Siyang Jing>

  \;

  Given string <math|s<around*|[|0,1,\<ldots\>,r-1|]>>,\ 

  denote Ascii: {ASCII characters} <math|\<rightarrow\>>
  <math|<around*|{|0,1,2,\<ldots\>,127|}>>,\ 

  denote <math|R<rsub|128>>: {strings} <math|\<rightarrow\>> {radix-128
  integers},

  then we have:

  <math|R<rsub|128><around*|(|s|)>=<big|sum><rsup|i=r-1><rsub|i=0>128<rsup|i>\<times\>Ascii<around*|(|s<around*|[|r-1-i|]>|)>>,

  By Horner's Rule, we have:

  <math|R<rsub|128><around*|(|s|)>=<around*|(|<around*|(|Ascii<around*|(|s<around*|[|0|]>|)>\<times\>128+Ascii<around*|(|s<around*|[|1|]>|)>|)>\<times\>128+\<ldots\>|)>\<times\>128+Ascii<around*|(|s<around*|[|r-1|]>|)>>

  \;

  Written sequentially, we have:

  \;

  <\indent>
    <math|f<rsub|0>=Ascii<around*|(|s<around*|[|0|]>|)>>

    <math|f<rsub|1>=f<rsub|0>\<times\>128+Ascii<around*|(|s<around*|[|1|]>|)>>

    <math|\<ldots\>>

    <math|f<rsub|k>=f<rsub|k-1>\<times\>128+Ascii<around*|(|s<around*|[|k|]>|)>>

    <math|\<ldots\>>

    <math|f<rsub|r-1>=f<rsub|r-2>\<times\>128+Ascii<around*|(|s<around*|[|r-1|]>|)>>

    <math|R<rsub|128><around*|(|s|)>=f<rsub|r-1>>
  </indent>

  \;

  By computation rules of mod, or rules of <math|\<bbb-Z\><rsub|m>>, we have:

  \;

  <\indent>
    <math|g<rsub|0>=Ascii<around*|(|s<around*|[|0|]>|)>%m>

    <math|g<rsub|1>=<around*|(|g<rsub|0>\<times\>128+Ascii<around*|(|s<around*|[|1|]>|)>|)>%m>

    <math|\<ldots\>>

    <math|g<rsub|k>=<around*|(|g<rsub|k-1>\<times\>128+Ascii<around*|(|s<around*|[|k|]>|)>|)>%m>

    <math|\<ldots\>>

    <math|g<rsub|r-1>=<around*|(|g<rsub|r-2>\<times\>128+Ascii<around*|(|s<around*|[|r-1|]>|)>|)>%m>

    <math|h<around*|(|s|)>=R<rsub|128><around*|(|s|)>%m=g<rsub|r-1>>
  </indent>

  \;

  From this, we can develop an iterative method to calculate the hash value.
  However, we have to pay attention to the details of each step. In
  calculating <math|g<rsub|k>=<around*|(|g<rsub|k-1>\<times\>128+Ascii<around*|(|s<around*|[|k|]>|)>|)>%m>,
  there are two potential sources of overflow, the multiplication and the
  addition.

  \;

  We first calculate <math|<wide|g|~><rsub|k>=<around*|(|g<rsub|k-1>\<times\>128|)>%m>
  through multiplication by 2 and take modulo <math|m>, repeating 7 times.
  Since <math|g<rsub|k-1>\<less\>m\<less\>2<rsup|31>>, multiplication by 2
  does not cause overflow, and since we modulo <math|m> everytime we multiply
  by 2, the process in all does not overflow.\ 

  \;

  Then we calculate <math|g<rsub|k>=<around*|(|<wide|g|~><rsub|k>+Ascii<around*|(|s<around*|[|k|]>|)>|)>%m>.
  Since <math|<wide|g|~><rsub|k>\<less\>m\<less\>2<rsup|31>> and
  <math|Ascii<around*|(|s<around*|[|k|]>|)>\<less\>128>, the addition does
  not overflow.

  \;

  Below are the algorithms.

  \;

  <paragraph|Algorithm: Times128Modm>

  <\indent>
    Input: <math|q>, <math|m>

    <math|p\<leftarrow\>q>

    for <math|i=1> to 7

    <\indent>
      <math|p\<leftarrow\><around*|(|p\<times\>2|)>%m>
    </indent>

    end

    Output: <math|p>
  </indent>

  This algorithm apparently only takes <math|O<around*|(|1|)>> space.

  \;

  <paragraph|Algorithm: StringHashDivisionMethod>

  <\indent>
    Input: string <math|s<around*|[|0,1,\<ldots\>,r-1|]>>

    <math|g\<leftarrow\>Ascii<around*|(|s<around*|[|0|]>|)>%m>

    for <math|i=1> to <math|r-1>

    <\indent>
      <math|g\<leftarrow\><around*|(|Times128Modm<around*|(|g,m|)>+Ascii<around*|(|s<around*|[|i|]>|)>|)>%m>
    </indent>

    end

    Output: <math|g>
  </indent>

  This algorithm itself only stores <math|g> and thus takes
  <math|O<around*|(|1|)>> space. In each iteration, the algorithm calls
  Times128Modm, and Times128Modm takes <math|O<around*|(|1|)>> space. The
  result of Times128Modm is not stored and is used immediately, and therefore
  in total the algorithm costs <math|O<around*|(|1|)>> space.

  \;

  \;
</body>

<\initial>
  <\collection>
    <associate|page-type|letter>
  </collection>
</initial>

<\references>
  <\collection>
    <associate|auto-1|<tuple|1|1|../../../.TeXmacs/texts/scratch/no_name_6.tm>>
    <associate|auto-2|<tuple|2|?|../../../.TeXmacs/texts/scratch/no_name_6.tm>>
  </collection>
</references>

<\auxiliary>
  <\collection>
    <\associate|toc>
      <with|par-left|<quote|4tab>|Algorithm
      <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-1><vspace|0.15fn>>
    </associate>
  </collection>
</auxiliary>