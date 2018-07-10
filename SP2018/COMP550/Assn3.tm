<TeXmacs|1.99.4>

<style|generic>

<\body>
  COMP 550

  Assignment 3

  Siyang Jing

  <\enumerate-alpha>
    <item>The pivot is chosen by line 1 of RANDOMIZED-PARTITION, through
    randomly selecting a number from <math|p> to <math|r>. Therefore, each
    element is chosen with equal probability, i.e. <math|1/n>.

    <center|<math|\<bbb-E\><around*|[|X<rsub|i>|]>=Pr>(<math|i>th smallest
    element is chosen as the pivot)=<math|1/n>>

    \;

    <item>We first discuss the cost for the subcase where <math|X<rsub|q>=1>,
    i.e. the <math|q>th smallest element has been chosen as the pivot. Then,
    the sorting consists of 3 steps, partitioning, sorting the elements
    <math|1> to <math|q-1>, and sorting the elements <math|q+1> to <math|n>.
    The cost for partitioning is <math|\<Theta\><around*|(|n|)>>, the cost
    for sorting the elements <math|1> to <math|q-1> is
    <math|T<around*|(|q-1-1+1|)>=T<around*|(|q-1|)>>, and the cost for
    sorting the elements <math|q+1> to <math|n> is
    <math|T<around*|(|n-<around*|(|q+1|)>+1|)>=T<around*|(|n-q|)>>.
    Therefore, we have, when <math|X<rsub|q>=1>,

    <\equation*>
      T<around*|(|n|)>=T<around*|(|q-1|)>+T<around*|(|n-q|)>+\<Theta\><around*|(|n|)>.
    </equation*>

    We then discuss the relation between the subcases. The events {<math|i>th
    smallest element is chosen as the pivot} for different <math|i>'s are
    disjoint, i.e. if <math|p>th smallest element has been chosen as the
    pivot, then <math|q>th smallest element cannot be the pivot, and the
    probability of their union is 1, i.e. one of them has to happen.
    Therefore, we have\ 

    <\equation*>
      T<around*|(|n|)>=<big|sum><rsup|n><rsub|q=1>X<rsub|q><around*|(|T<around*|(|q-1|)>+T<around*|(|n-q|)>+\<Theta\><around*|(|n|)>|)>,
    </equation*>

    and therefore\ 

    <\equation*>
      \<bbb-E\><around*|[|T<around*|(|n|)>|]>=\<bbb-E\><around*|[|<big|sum><rsup|n><rsub|q=1>X<rsub|q><around*|(|T<around*|(|q-1|)>+T<around*|(|n-q|)>+\<Theta\><around*|(|n|)>|)>|]>
    </equation*>

    \;

    <item><math|\<bbb-E\><around*|[|T<around*|(|n|)>|]>>

    <math|=\<bbb-E\><around*|[|<big|sum><rsup|n><rsub|q=1>X<rsub|q><around*|(|T<around*|(|q-1|)>+T<around*|(|n-q|)>+\<Theta\><around*|(|n|)>|)>|]>>

    <math|=<big|sum><rsup|n><rsub|q=1>\<bbb-E\><around*|[|X<rsub|q><around*|(|T<around*|(|q-1|)>+T<around*|(|n-q|)>+\<Theta\><around*|(|n|)>|)>|]>>,
    by linearity of <math|\<bbb-E\>> operator

    we notice that <math|X<rsub|q>> only depends on choice of this pivot, and
    <math|<around*|(|T<around*|(|q-1|)>+T<around*|(|n-q|)>+\<Theta\><around*|(|n|)>|)>>
    does not depend on choice of this pivot, and therefore, they are
    independent, and therefore we have:

    <math|=<big|sum><rsup|n><rsub|q=1><around*|(|\<bbb-E\><around*|[|X<rsub|q>|]>\<bbb-E\><around*|[|T<around*|(|q-1|)>+T<around*|(|n-q|)>+\<Theta\><around*|(|n|)>|]>|)>>

    <math|=<big|sum><rsup|n><rsub|q=1><around*|(|<frac|1|n>\<bbb-E\><around*|[|T<around*|(|q-1|)>+T<around*|(|n-q|)>+\<Theta\><around*|(|n|)>|]>|)>>

    <math|=<frac|1|n><big|sum><rsup|n><rsub|q=1><around*|(|\<bbb-E\><around*|[|T<around*|(|q-1|)>|]>+\<bbb-E\><around*|[|T<around*|(|n-q|)>|]>+\<Theta\><around*|(|n|)>|)>>,
    by linearity of <math|\<bbb-E\>>

    we notice that the term corresponding to <math|q=k> and <math|q=n+1-k>
    are identical, just in reverse order, and that if <math|n> is odd, then
    for <math|q=<frac|n+1|2>>\<#FF0C\><math|><math|\<bbb-E\><around*|[|T<around*|(|q-1|)>|]>>
    and <math|\<bbb-E\><around*|[|T<around*|(|n-q|)>|]>> are identical,
    therefore, by a change in the order of the summation, we have

    <math|=<frac|1|n><big|sum><rsup|n><rsub|q=1>2\<bbb-E\><around*|[|T<around*|(|q-1|)>|]>+\<Theta\><around*|(|n|)>>

    <math|=<frac|2|n><big|sum><rsup|n><rsub|q=1>\<bbb-E\><around*|[|T<around*|(|q-1|)>|]>+\<Theta\><around*|(|n|)>>

    since <math|T<around*|(|1|)>=T<around*|(|0|)>=\<Theta\><around*|(|1|)>>
    are ignorable, by a change of variable <math|q\<rightarrow\>q-1>, we have

    <math|=<frac|2|n><big|sum><rsup|n-1><rsub|q=2>\<bbb-E\><around*|[|T<around*|(|q|)>|]>+\<Theta\><around*|(|n|)>>

    \;

    <item><math|<big|sum><rsup|n-1><rsub|k=2>k*lg*k>

    <math|=<big|sum><rsup|n-1><rsub|k=1>k*lg*k>

    <math|=<big|sum><rsup|<around*|\<lceil\>|<frac|n|2>|\<rceil\>>-1><rsub|k=1>k*lg*k+<big|sum><rsup|n-1><rsub|k=<around*|\<lceil\>|<frac|n|2>|\<rceil\>>>k*lg*k>

    <\math>
      \<leqslant\><big|sum><rsup|<around*|\<lceil\>|<frac|n|2>|\<rceil\>>-1><rsub|k=1>k*lg*<frac|n|2>+<big|sum><rsup|n-1><rsub|k=<around*|\<lceil\>|<frac|n|2>|\<rceil\>>>k*lg*n
    </math>

    <math|=<big|sum><rsup|<around*|\<lceil\>|<frac|n|2>|\<rceil\>>-1><rsub|k=1>k<around*|(|-1+lg*n|)>+<big|sum><rsup|n-1><rsub|k=<around*|\<lceil\>|<frac|n|2>|\<rceil\>>>k*lg*n>

    <math|=lg*n<big|sum><rsup|n-1><rsub|k=1>k*-<big|sum><rsup|<around*|\<lceil\>|<frac|n|2>|\<rceil\>>-1><rsub|k=1>k>

    <math|\<leqslant\><frac|n<rsup|2>-n|2>lg*n-<frac|<frac|n|2><around*|(|<frac|n|2>-1|)>|2>>

    <math|\<leqslant\><frac|1|2>n<rsup|2>lg*n-<frac|1|8>n<rsup|2>+<frac|n|2><around*|(|<frac|1|2>-lg*n|)>>

    <math|\<leqslant\><frac|1|2>n<rsup|2>lg*n-<frac|1|8>n<rsup|2>>, since
    <math|n\<geqslant\>2\<rightarrow\>lg*n\<geqslant\>1\<rightarrow\><frac|1|2>-lg*n\<less\>0\<rightarrow\><frac|n|2><around*|(|<frac|1|2>-lg*n|)>\<less\>0>

    \;

    <item>We first notice that

    <\equation*>
      \<bbb-E\><around*|[|T<around*|(|n|)>|]>=<frac|2|n><big|sum><rsup|n-1><rsub|q=2><around*|(|\<bbb-E\><around*|[|T<around*|(|q|)>|]>+\<Theta\><around*|(|n|)>|)>=\<Theta\><around*|(|n|)>+<frac|2|n><big|sum><rsup|n-1><rsub|q=2>\<bbb-E\><around*|[|T<around*|(|q|)>|]>
    </equation*>

    We assume <math|\<Theta\><around*|(|n|)>> in the equation above means
    <math|\<exists\>c<rsub|1>,c<rsub|2>\<in\>\<bbb-R\><rsup|+>,s.t.\<forall\>n\<geqslant\>2,0\<less\>c<rsub|1>n\<leqslant\>\<Theta\><around*|(|n|)>\<leqslant\>c<rsub|2>n>.\ 

    Note that we can write <math|\<forall\>n\<geqslant\>2> instead of
    <math|\<forall\>n\<geqslant\>n<rsub|0>>, for some <math|n<rsub|0>>
    potentially larger than 2, since we know from the algorithm that for any
    <math|n\<geqslant\>2>, the partition step is approximately proportional
    to <math|n>.

    We prove <math|><math|\<bbb-E\><around*|[|T<around*|(|n|)>|]>\<in\>\<Theta\><around*|(|n*lg*n|)>>
    in two parts, <math|\<bbb-E\><around*|[|T<around*|(|n|)>|]>\<in\>\<Omicron\><around*|(|n*lg*n|)>>
    and <math|\<bbb-E\><around*|[|T<around*|(|n|)>|]>\<in\>\<Omega\><around*|(|n*lg*n|)>>.

    We first prove <math|\<bbb-E\><around*|[|T<around*|(|n|)>|]>\<in\>\<Omicron\><around*|(|n*lg*n|)>>,
    by finding <math|a>, s.t. <math|\<forall\>n\<geqslant\>2,\<bbb-E\><around*|[|T<around*|(|n|)>|]>\<leqslant\>a*n*lg*n>.
    We prove this by induction.

    \;

    <\indent>
      We first cover the base cases, i.e. select <math|a> large enough s.t.
      <math|\<bbb-E\><around*|[|T<around*|(|2|)>|]>\<leqslant\>a*2*lg*2>.
      Note that <math|\<bbb-E\><around*|[|T<around*|(|2|)>|]>> is a constant,
      which we don't have to explicitly write down, and therefore here
      <math|a> is well-defined.

      We then assume <math|\<bbb-E\><around*|[|T<around*|(|k|)>|]>\<leqslant\>a*k*lg*k>
      for all <math|2\<leqslant\>k\<less\>n>.

      <\equation*>
        <frac|2|n><big|sum><rsup|n-1><rsub|q=2>\<bbb-E\><around*|[|T<around*|(|q|)>|]>\<leqslant\><frac|2|n><big|sum><rsup|n-1><rsub|q=2>a*q*lg*q\<leqslant\><frac|2a|n><around*|(|<frac|1|2>n<rsup|2>lg*n-<frac|1|8>n<rsup|2>|)>\<leqslant\>a*n*lg*n-<frac|a|4>n
      </equation*>

      <\eqnarray*>
        <tformat|<table|<row|<cell|\<bbb-E\><around*|[|T<around*|(|n|)>|]>=\<Theta\><around*|(|n|)>+<frac|2|n><big|sum><rsup|n-1><rsub|q=2>\<bbb-E\><around*|[|T<around*|(|q|)>|]>\<leqslant\>\<Theta\><around*|(|n|)>+a*n*lg*n-<frac|a|4>n\<leqslant\>a*n*lg*n+c<rsub|2>n-<frac|a|4>n>|<cell|<around*|(|*\<ast\>|)>>|<cell|>>>>
      </eqnarray*>

      We let <math|a\<geqslant\>4c<rsub|2>>, then we have

      <\equation*>
        a*\<geqslant\>4c<rsub|2>\<rightarrow\>c<rsub|2>n-<frac|a|4>n\<leqslant\>0\<rightarrow\><around*|(|\<ast\>|)>\<leqslant\>a*n*lg*n
      </equation*>

      In conclusion, we have successfully found
      <math|a=max<around*|(|<frac|\<bbb-E\><around*|[|T<around*|(|2|)>|]>|2*>,4c<rsub|2>|)>>.
    </indent>

    \;

    We then prove <math|\<bbb-E\><around*|[|T<around*|(|n|)>|]>\<in\>\<Omega\><around*|(|n*lg*n|)>>,
    by finding <math|b>, s.t. <math|\<forall\>n\<geqslant\>2,\<bbb-E\><around*|[|T<around*|(|n|)>|]>\<geqslant\>b*n*lg*n>.

    \;

    <\indent>
      We first find a lower bound for <math|<big|sum><rsup|n-1><rsub|k=2>k*lg*k>.

      Since <math|<rsup|>k*lg*k> is monotonically increasing in <math|k>, we
      have\ 

      <\eqnarray*>
        <tformat|<table|<row|<cell|<big|sum><rsup|n-1><rsub|k=2>k*lg*k\<geqslant\><big|int><rsup|n-1><rsub|1>x*lg*x*d<rsup|>x=<around*|\<nobracket\>|<frac|1|2>x<rsup|2>lg*x-<frac|1|4log2>x<rsup|2>|\|><rsub|x=1><rsup|x=n-1>\<gtr\><frac|1|2><around*|(|n-1|)><rsup|2>lg*<around*|(|n-1|)>-<frac|1|4log2><around*|(|n-1|)><rsup|2>>|<cell|<around*|(|\<ast\>\<ast\>|)>>|<cell|>>>>
      </eqnarray*>

      <math|>

      We notice that <math|lg<around*|(|n|)>-lg<around*|(|n-1|)>=lg<around*|(|<frac|n|n-1>|)>=lg<around*|(|1+<frac|1|n-1>|)>\<leqslant\>1>,
      so we have:

      <\equation*>
        <around*|(|\<ast\>\<ast\>|)>\<geqslant\><frac|1|2><around*|(|n-1|)><rsup|2><around*|(|lg<around*|(|n|)>-1|)>-<frac|<around*|(|n-1|)><rsup|2>|4log2>\<gtr\><frac|1|2>n<rsup|2>lg<rsup|>n-n<rsup|>lg<rsup|>n-<frac|1|2><around*|(|n-1|)><rsup|2>-<frac|<around*|(|n-1|)><rsup|2>|2>\<gtr\><frac|1|2>n<rsup|2>lg<rsup|>n-2n<rsup|2>
      </equation*>
    </indent>

    \;

    We proceed our proof of <math|\<bbb-E\><around*|[|T<around*|(|n|)>|]>\<geqslant\>b*n*lg*n>,
    by induction on <math|n>.

    \;

    <\indent>
      We first cover the base cases, i.e. select <math|b> large enough s.t.
      <math|\<bbb-E\><around*|[|T<around*|(|2|)>|]>\<geqslant\>b*2*lg*2>.

      We then assume <math|\<bbb-E\><around*|[|T<around*|(|k|)>|]>\<geqslant\>b*k*lg*k>
      for all <math|2\<leqslant\>k\<less\>n>.

      <\equation*>
        <frac|2|n><big|sum><rsup|n-1><rsub|q=2>\<bbb-E\><around*|[|T<around*|(|q|)>|]>\<geqslant\><frac|2|n><big|sum><rsup|n-1><rsub|q=2>b*q*lg*q\<geqslant\><frac|2b|n><around*|(|<frac|1|2>n<rsup|2>lg*n-2n<rsup|2>|)>\<geqslant\>b*n*lg*n-4<rsup|>*b*n
      </equation*>

      <\eqnarray*>
        <tformat|<table|<row|<cell|\<bbb-E\><around*|[|T<around*|(|n|)>|]>=\<Theta\><around*|(|n|)>+<frac|2|n><big|sum><rsup|n-1><rsub|q=2>\<bbb-E\><around*|[|T<around*|(|q|)>|]>\<geqslant\>\<Theta\><around*|(|n|)>+b*n*lg*n-4b<rsup|>n\<geqslant\>b*n*lg*n+<around*|(|c<rsub|1>-4b|)>n>|<cell|<around*|(|*\<ast\>\<ast\>\<ast\>|)>>|<cell|>>>>
      </eqnarray*>

      We let <math|b\<leqslant\><frac|c<rsub|1>|4>>, then we have

      <\equation*>
        <around*|(|c<rsub|1>-4b|)>n\<geqslant\>0\<rightarrow\><around*|(|\<ast\>\<ast\>\<ast\>|)>\<geqslant\>b*n*lg*n
      </equation*>

      In conclusion, we have successfully found
      <math|b=min<around*|(|<frac|\<bbb-E\><around*|[|T<around*|(|2|)>|]>|2*>,<frac|c<rsub|1>|4>|)>>
    </indent>
  </enumerate-alpha>

  \;
</body>

<\initial>
  <\collection>
    <associate|page-type|letter>
  </collection>
</initial>