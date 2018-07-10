<TeXmacs|1.99.4>

<style|generic>

<\body>
  \;

  \;

  Part III

  Figure 1 describes the dependence of solution on <math|Z<rsub|0>>,
  <math|I<rsub|0>>, <math|Q<rsub|0>>, and <math|R<rsub|0>>. The different
  colors correspond to the values of <math|Z<rsub|0>>. For each
  <math|Z<rsub|0>>, the solutions from different <math|I<rsub|0>>,
  <math|Q<rsub|0>>, and <math|R<rsub|0>> are ploted with the same color.
  <math|\<kappa\>>, <math|\<gamma\>>, and <math|\<sigma\>> are assigned with
  constant value <math|0.1>.

  We can see Figure 1 that the solution does not highly depend on
  <math|I<rsub|0>>, <math|Q<rsub|0>>, and <math|R<rsub|0>>, since the lines
  with the same color basically overlap with each other. The only significant
  dependence is <math|Z<rsub|0>>.

  \;

  Report4Part3Fig1.0.fig;

  \;

  Figure 2 describes the dependence of solution on <math|Z<rsub|0>>,
  <math|\<kappa\>>, <math|\<gamma\>>, and <math|\<sigma\>>. Since we already
  know that <math|I<rsub|0>>, <math|Q<rsub|0>>, and <math|R<rsub|0>> do not
  affect the solution significantly, we can assign <math|I<rsub|0>>,
  <math|Q<rsub|0>>, and <math|R<rsub|0>> with a constant value, say
  <math|3e8>. The different colors correspond to the values of
  <math|Z<rsub|0>>. For each <math|Z<rsub|0>>, the solutions from different
  <math|\<kappa\>>, <math|\<gamma\>>, and <math|\<sigma\>> are ploted with
  the same color.

  We can see Figure 2 that the solution does not highly depend on
  <math|\<kappa\>>, <math|\<gamma\>>, and <math|\<sigma\>>, since the lines
  with the same color basically overlap with each other. The only significant
  dependence is <math|Z<rsub|0>>.

  \;

  Report4Part3Fig2.0.fig;

  \;

  We then examines the difference between solutions of Part I, Part II, and
  Part III. Since we already know that \ <math|I<rsub|0>>, <math|Q<rsub|0>>,
  and <math|R<rsub|0>>, and <math|\<kappa\>>, <math|\<gamma\>>, and
  <math|\<sigma\>> do not have significant influence on the solution. We will
  fix them as constants. In Figure 3, colors correspond to the values of
  <math|Z<rsub|0>>, and solutions of Part I is ploted with dotted line,
  solutions of Part II with dashed line, and solutions of Part III with solid
  line.

  \;

  Report4Part3Fig3.0.fig;

  \;

  We can see from Figure 3 that the solutions of Part II and Part III are
  essentially the same, which implies that quarantine probably does not help
  much.

  Same with Part II, we can compute the threshold value above which <math|S>
  will decay below 1 in <math|1e-3> time, which basically means human
  extinction. With the same method described in Part II, we compute such
  value is <math|1.5946e8>, which is, in fact, very close to the one we get
  in Part II.

  \;

  Optional:

  Furthermore, although, as stated above, the values of <math|I<rsub|0>>,
  <math|Q<rsub|0>>, and <math|R<rsub|0>>, and <math|\<kappa\>>,
  <math|\<gamma\>>, and <math|\<sigma\>> do not have significant influence on
  the solution, we are still curious about the order of magnitude and the
  pattern of their influence on the solution.

  In Figure 4, we fix the values of <math|I<rsub|0>>, <math|Q<rsub|0>>, and
  <math|R<rsub|0>>, and in Figure 5, we fix the values of <math|\<kappa\>>,
  <math|\<gamma\>>, and <math|\<sigma\>>. In Figure 4 and 5, for each value
  of <math|Z<rsub|0>>, we compute a base solution <math|X<rsub|b>>, with
  <math|I<rsub|0>>, <math|Q<rsub|0>>, and <math|R<rsub|0>>/<math|\<kappa\>>,
  <math|\<gamma\>>, and <math|\<sigma\>> set to zero, respectively. Then, for
  each combination of non-zero <math|I<rsub|0>>, <math|Q<rsub|0>>, and
  <math|R<rsub|0>>/<math|\<kappa\>>, <math|\<gamma\>>, and <math|\<sigma\>>,
  we get a new solution <math|X>, and we plot the difference
  <math|X-X<rsub|b>> with the color corresponding to the value of
  <math|Z<rsub|0>>.

  \;
</body>

<\initial>
  <\collection>
    <associate|page-type|letter>
  </collection>
</initial>