<TeXmacs|1.99.4>

<style|generic>

<\body>
  <\math>
    Let A be an array,and let\<less\>be a strict weak ordering on the
    elements of A.
  </math>

  A sorting algorithm is stable if:

  <math|i\<less\>j\<wedge\>A<around*|[|i|]>=A<around*|[|j|]>\<rightarrow\>
  \<pi\><around*|(|i|)>\<less\>\<pi\><around*|(|j|)>>, where <math|\<pi\>> is
  the permutation.

  Equivalently, <math|\<forall\>i\<neq\>j,s.t.A<around*|[|i|]>=A<around*|[|j|]>,i\<less\>j\<rightarrow\>\<pi\><around*|(|i|)>\<less\>\<pi\><around*|(|j|)>>.

  Inverse: <math|\<forall\>i\<neq\>j,s.t.A<around*|[|i|]>=A<around*|[|j|]>,\<pi\><around*|(|i|)>\<less\>\<pi\><around*|(|j|)>\<rightarrow\>i\<less\>j>,
  is it true?

  Notice that since <math|\<pi\>> is permutation, <math|i=j> case need not be
  considered.

  Suppose <math|\<exists\>i\<neq\>j,A<around*|[|i|]>=A<around*|[|j|]>,\<pi\><around*|(|i|)>\<less\>\<pi\><around*|(|j|)>\<wedge\>i\<gtr\>j>,
  then we have <math|j\<less\>i>, which implies
  <math|\<pi\><around*|(|j|)>\<less\>\<pi\><around*|(|i|)>>, conrtadiction.

  \;

  Now suppose the inverse is true, then is the original true?

  Suppose \ <math|\<exists\>i\<neq\>j,A<around*|[|i|]>=A<around*|[|j|]>,i\<less\>j\<wedge\>\<pi\><around*|(|i|)>\<gtr\>\<pi\><around*|(|j|)>>,
  then we have <math|\<pi\><around*|(|j|)>\<less\>\<pi\><around*|(|i|)>>,
  which implies <math|j\<less\>i>, contradiction.

  \;

  Note: Heuristically speaking,

  \Pthe latter order is the same as the previous order\Q\ 

  is equivalent to\ 

  \Pthe previous order is the same as the latter order\Q.

  \;

  A different notation:

  Suppose <math|<around*|[|1,2,3,\<ldots\>,n|]>\<rightarrow\><around*|[|p<rsub|1>,p<rsub|2>,\<ldots\>,p<rsub|n>|]>>,
  then we have <math|i=p<rsub|\<pi\><around*|(|i|)>>>,
  <math|A<around*|[|i|]>> moved to <math|A<around*|[|p<rsub|\<pi\><around*|(|i|)>>|]>>

  Consider <math|p<rsub|i>> as <math|p<around*|(|i|)>>, then we have
  <math|p=\<pi\><rsup|-1>>.

  Then an equivalent definition is:

  <math|i\<less\>j\<wedge\>A<around*|[|p<rsub|i>|]>=A<around*|[|p<rsub|j>|]>\<rightarrow\>p<rsub|i>\<less\>p<rsub|j>>,
  i.e.

  <math|\<pi\><around*|(|p<rsub|i>|)>\<less\>\<pi\><around*|(|p<rsub|j>|)>\<wedge\>A<around*|[|p<rsub|i>|]>=A<around*|[|p<rsub|j>|]>\<rightarrow\>p<rsub|i>\<less\>p<rsub|j>>,
  i.e.

  <math|\<pi\><around*|(|i|)>\<less\>\<pi\><around*|(|j|)>\<wedge\>A<around*|[|i|]>=A<around*|[|j|]>\<rightarrow\>i\<less\>j>

  \;

  Proof:

  Suppose\ 

  \;
</body>

<\initial>
  <\collection>
    <associate|page-type|letter>
  </collection>
</initial>