<TeXmacs|1.99.4>

<style|generic>

<\body>
  1.

  (a)10%

  (b)1%

  (c)1e-100

  (d)The higher the dimension is, the smaller the order of magnitude of the
  proportion of data is that is used for any given test observation. Suppose
  the training set is close to evenly distributed, and the order of magnitude
  is approximately the same across different dimensions, then it's clear that
  there are fewer (of smaller order of magnitude) training observations
  \Pnear\Q (with the same range in one dimension) any given point.

  (e)

  <math|p=1:> 0.1

  <math|p=2:> <math|<sqrt|0.1>\<approx\>0.316>

  <math|p=100:> <math|<sqrt|0.1|100>\<approx\>0.977>

  \;

  \;

  \;

  \;

  \;

  \;

  3.

  <\math>
    <around*|(|a|)>a<rsub|1>=\<beta\><rsub|0>,b<rsub|1>=\<beta\><rsub|1>,c<rsub|1>=\<beta\><rsub|2>,d<rsub|1>=\<beta\><rsub|3>

    <around*|(|b|)>a<rsub|2>=\<beta\><rsub|0>-\<beta\><rsub|4>\<xi\><rsup|3>,b<rsub|2>=\<beta\><rsub|1>+\<beta\><rsub|4>\<xi\><rsup|2>,c<rsub|2>=\<beta\><rsub|2>-\<beta\><rsub|4>\<xi\>,d<rsub|2>=\<beta\><rsub|3>+\<beta\><rsub|4>
  </math>

  <math|<around*|(|c|)><around*|(|d|)><around*|(|e|)>>Notice that
  <math|f<rsub|1><around*|(|x|)>=\<beta\><rsub|0>+\<beta\><rsub|1>x+\<beta\><rsub|2>x<rsup|2>+\<beta\><rsub|3>x<rsup|3>>,
  <math|f<rsub|2><around*|(|x|)>=\<beta\><rsub|0>+\<beta\><rsub|1>x+\<beta\><rsub|2>x<rsup|2>+\<beta\><rsub|3>x<rsup|3>+\<beta\><rsub|4><around*|(|x-\<xi\>|)><rsup|3>>

  <math|f<rsub|2><around*|(|x|)>-f<rsub|1><around*|(|x|)>=\<beta\><rsub|4><around*|(|x-\<xi\>|)><rsup|3>>

  Apprently <math|f<rsub|1><around*|(|\<xi\>|)>=f<rsub|2><around*|(|\<xi\>|)>>,
  since the term vanishes.

  <math|f<rprime|'><rsub|2><around*|(|x|)>-f<rprime|'><rsub|1><around*|(|x|)>=3\<beta\><rsub|4><around*|(|x-\<xi\>|)><rsup|2>>

  <math|f<rprime|''><rsub|2><around*|(|x|)>-f<rprime|''><rsub|1><around*|(|x|)>=6\<beta\><rsub|4><around*|(|x-\<xi\>|)>>

  Similarly, <math|f<rprime|'><rsub|1><around*|(|\<xi\>|)>=f<rprime|'><rsub|2><around*|(|\<xi\>|)>>
  and <math|f<rprime|''><rsub|1><around*|(|\<xi\>|)>=f<rprime|''><rsub|2><around*|(|\<xi\>|)>>
  hold since the above terms vanish.

  \;

  4.

  <math|<around*|(|a|)><around*|(|b|)>>As <math|\<lambda\>> approaches
  infinity, the second term, the penalty term, of the loss function
  dominates, and it has to be minimized to achieve the <math|argmin>, i.e.,
  the <math|<wide|g|^><rsub|1,2>>. Therefore, the penalty term has to be
  zero, which means the <math|<wide|g|^><rsub|1>> is a polynomial of order 2
  (or less), and <math|<wide|g|^><rsub|2>> order 3 (or less), that minimize
  the first term.

  Therefore, <math|<wide|g|^><rsub|2>> has less training error than
  <math|<wide|g|^><rsub|1>>.

  Generally speaking, <math|<wide|g|^><rsub|1>> should be smoother than
  <math|<wide|g|^><rsub|2>>, and thus is more likely to prevent overfitting,
  and thus <math|<wide|g|^><rsub|1>> is likely to have less test RSS.

  <math|>

  \;
</body>

<\initial>
  <\collection>
    <associate|page-type|letter>
  </collection>
</initial>