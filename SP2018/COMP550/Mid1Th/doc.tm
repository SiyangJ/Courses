<TeXmacs|1.99.4>

<style|generic>

<\body>
  Algorithm Potion-Adding-Order(<math|v>)

  <\indent>
    <math|n=v>.length

    let <math|m<around*|[|1\<ldots\>n,1\<ldots\>n|]>>,
    <math|f<around*|[|1\<ldots\>n,1\<ldots\>n|]>>, and
    <math|s<around*|[|1\<ldots\>n-1,2\<ldots\>n|]>> be new tables

    for <math|i=1> to <math|n>

    <\indent>
      <math|m<around*|[|i,i|]>=0>

      <math|f<around*|[|i,i|]>=v<around*|[|i|]>>

      for <math|j=i+1> to <math|n>

      <\indent>
        <math|f<around*|[|i,j|]>=f<around*|[|i,j-1|]>+v<around*|[|j|]>> mod
        <math|50>
      </indent>

      end
    </indent>

    end

    for <math|l=2> to <math|n>

    <\indent>
      for <math|i=1> to <math|n-l+1>

      <\indent>
        <math|j=i+l-1>

        <\math>
          m<around*|[|i,j|]>=\<infty\>
        </math>

        for <math|k=i> to <math|j-1>

        <\indent>
          <math|q=m<around*|[|i,k|]>+m<around*|[|k+1,j|]>+f<around*|[|i,k|]>\<times\>f<around*|[|k+1,j|]>>

          if <math|q\<less\>m<around*|[|i,j|]>>

          <\indent>
            <math|m<around*|[|i,j|]>=q>

            <math|s<around*|[|i,j|]>=k>
          </indent>

          end
        </indent>

        end
      </indent>

      end
    </indent>

    end

    return <math|m> and <math|s>
  </indent>

  \;

  Print-Optimal-Parenthesis(<math|><math|s,i,j>)

  <\indent>
    if <math|i>==<math|j>

    <\indent>
      print <math|v<around*|[|i|]>>
    </indent>

    else\ 

    <\indent>
      print \P(\Q

      Print-Optimal-Parenthesis(<math|s,i,s<around*|[|i,j|]>>)

      Print-Optimal-Parenthesis(<math|s,s<around*|[|i,j|]>+1,j>)

      print \P)\Q
    </indent>

    end
  </indent>

  <\indent>
    \;
  </indent>
</body>

<\initial>
  <\collection>
    <associate|page-type|letter>
  </collection>
</initial>