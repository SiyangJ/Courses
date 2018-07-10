<TeXmacs|1.99.4>

<style|generic>

<\body>
  <\enumerate-numeric>
    <item>

    <\enumerate-roman>
      <item>Let <math|\<b-Y\>=<around*|(|<tabular|<tformat|<table|<row|<cell|Y<rsub|1>>>|<row|<cell|Y<rsub|2>>>|<row|<cell|\<ldots\>>>|<row|<cell|Y<rsub|n>>>>>>|)><rsup|>>,
      let <math|\<b-X\>=<around*|(|<tabular|<tformat|<table|<row|<cell|\<b-X\><rsup|T><rsub|1>>>|<row|<cell|\<b-X\><rsup|T><rsub|2>>>|<row|<cell|\<ldots\>>>|<row|<cell|\<b-X\><rsup|T><rsub|n>>>>>>|)>>,
      and let <math|\<b-epsilon\>=<around*|(|<tabular|<tformat|<table|<row|<cell|\<epsilon\><rsub|1>>>|<row|<cell|\<epsilon\><rsub|2>>>|<row|<cell|\<ldots\>>>|<row|<cell|\<epsilon\><rsub|n>>>>>>|)>>.
      Then we have the following model:

      <\equation*>
        \<b-Y\>=\<b-X\>\<b-beta\>+\<b-epsilon\>
      </equation*>

      <item>The square error is <math|R<rsup|2>=<around*|\<\|\|\>|\<b-epsilon\>|\<\|\|\>><rsub|2><rsup|2>=<around*|\<\|\|\>|\<b-Y\>-\<b-X\>\<b-beta\>|\<\|\|\>><rsup|2><rsub|2>=<around*|(|\<b-Y\>-\<b-X\>\<b-beta\>|)>\<cdot\><around*|(|\<b-Y\>-\<b-X\>\<b-beta\>|)>>.
      In this case, <math|\<sigma\><rsup|2>=R<rsup|2>>. The least sqare error
      fit for <math|\<b-beta\>>, <math|<wide|\<b-beta\><rsub|>|^><rsub|LS>>
      is the value that minimizes such square error, i.e.
      <math|<wide|\<b-beta\><rsub|>|^><rsub|LS>=<below|argmin|\<b-beta\>><around*|(|R<rsup|2>|)>>.
      Therefore we have:\ 

      <\eqnarray*>
        <tformat|<table|<row|<cell|\<nabla\><around*|(|R<rsup|2><around*|(|\<b-beta\>|)>|)><around*|\||<rsub|<wide|\<b-beta\><rsub|>|^><rsub|LS>>=\<b-0\>|\<nobracket\>>>|<cell|>|<cell|>>|<row|<cell|\<nabla\><around*|(|-2\<b-Y\>\<cdot\>\<b-X\>\<b-beta\>+\<b-X\>\<b-beta\>\<cdot\>\<b-X\>\<b-beta\>|)>=\<b-0\>>|<cell|>|<cell|>>|<row|<cell|2<around*|(|\<b-X\><rsup|T>\<b-X\>|)><wide|\<b-beta\><rsub|>|^><rsub|LS>=2\<b-X\><rsup|T>\<b-Y\>>|<cell|>|<cell|>>|<row|<cell|<wide|\<b-beta\><rsub|>|^><rsub|LS>=<around*|(|\<b-X\><rsup|T>\<b-X\>|)><rsup|-1>\<b-X\><rsup|T>\<b-Y\>>|<cell|>|<cell|>>>>
      </eqnarray*>

      <item>
    </enumerate-roman>

    <item>

    <\enumerate-roman>
      <item>
    </enumerate-roman>
  </enumerate-numeric>
</body>

<\initial>
  <\collection>
    <associate|page-type|letter>
  </collection>
</initial>