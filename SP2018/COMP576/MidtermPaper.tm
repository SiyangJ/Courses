<TeXmacs|1.99.4>

<style|generic>

<\body>
  COMP 576 Spring 2018

  Midterm Correction

  Siyang Jing\ 

  PID: 730042022

  \;

  <\itemize>
    <item>Question 5:

    Which of the following is not a property of the sinusoids used as basis
    images when a shift-invariant, linear operator is to be applied?

    Correct Answer: They capture the position of an object in an image well

    Sinusoids use a global aperture. They are in some sense global funtions.
    They do not reflect information at some particula location. Therefore,
    they do not capture the position of a object in an image well.

    My Answer: At each frequency there are more than one sinusoid, which
    differ in phase

    At each frequency, there are two sinusoids that differ in phase. To be
    exact, for each <math|k>, they are <math|sin<around*|(|2\<pi\><dfrac|k|N>x|)>>
    and <math|cos<around*|(|2\<pi\><dfrac|k|N>x|)>>.

    <item>Question 12:

    Which is not a reason for requiring an aperture to be Gaussian?

    Correct Answer: The Fourier transform of a Gaussian is proportional to a
    Gaussian.

    Desired properties of an aperture are:

    <\indent>
      <\itemize>
        <item>Unbiased re spatial scaling, translation and rotation

        <item>Cascading apertures gives a legal aperture

        <item>Do not create structure, only eliminate it

        <item>Have finite integral
      </itemize>
    </indent>

    The Fourier transform of a Gaussian being proportional to a Gaussian is
    not directly related to any of the above.

    My Answer: A Gaussian with double the RMS width of another Gaussian
    applied to an image spatially scaled by 2, with the result scaled by
    <math|<dfrac|1|2>> is equivalent to applying the original Gaussian to the
    original image.

    This is due to the fact that Gaussian is unbiased with respect to spatial
    scaling, which is indeed a desired property of an aperture. Along the
    same line, we also want the aperture to be unbiased with respect to
    translation and rotation.

    <item>Question 15:

    Consider an image whose values are the result of convolution of a
    Gaussian of RMS width <math|\<sigma\>> with a diagonal line. That image
    will look like a blurry diagonal bar. If you wanted a kernel that when
    convolved with the image had highest values along the diagonal (along the
    center of the bar), what would be the best kernel to use?

    Correct Answer: The Gaussian of RMS width <math|\<sigma\>> applied to a
    bar of some length along that diagonal.

    The highest response is achieved when we convolve the image with the
    matched filter.

    My Answer: The second derivative, twice in the direction orthogonal to
    the diagonal along which the bar lies, of a Gaussian of RMS width
    <math|\<sigma\>>

    Although this option does give some indication of barness along the
    diagonal, it's not the highest.

    <item>Question 24:

    State which is true about image basis sets that are non-orthogonal.

    Correct Answer: Derivative operators fall into that class.

    The derivatives, when viewed as basis images, are indeed non-orthogonal.
    Some of the orthogonal basis images we have learnt are Fourier transform,
    SVD, and orthogonal wavelets.

    My Answer: None of the above.

    Since derivatives are indeed non-orthogonal, we cannot choose none of the
    above.

    \;

    \;

    <\itemize>
      \;

      \;
    </itemize>
  </itemize>
</body>

<\initial>
  <\collection>
    <associate|page-type|letter>
  </collection>
</initial>

<\references>
  <\collection>
    <associate|takeAssessmentForm:j_id_jsp_216698671_141:0:j_id_jsp_216698671_201:4:deliverMultipleChoiceSingleCorrect:j_id_jsp_216698671_1138|<tuple|<with|mode|<quote|math>|<rigid|\<circ\>>>|?|../../../.TeXmacs/texts/scratch/no_name_5.tm>>
    <associate|takeAssessmentForm:j_id_jsp_216698671_141:0:j_id_jsp_216698671_201:4:deliverMultipleChoiceSingleCorrect:j_id_jsp_216698671_1138:0:image2|<tuple|<with|mode|<quote|math>|<rigid|\<circ\>>>|?|../../../.TeXmacs/texts/scratch/no_name_5.tm>>
  </collection>
</references>