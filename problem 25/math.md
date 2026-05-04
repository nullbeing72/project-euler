## Binet’s Formula and Digit Count of Fibonacci Numbers

We start with Binet’s formula:

$$
F_n = \frac{\phi^n - \psi^n}{\sqrt{5}}, \quad \forall n \in \mathbb{Z}_{>0}
$$

where

$$
\phi = \frac{1+\sqrt{5}}{2}, \quad \psi = \frac{1-\sqrt{5}}{2}.
$$

---

### Key Properties

$$
\phi > 1, \quad |\psi| < 1.
$$

Since $|\psi| < 1$, we have:

$$
\psi^n \to 0 \quad \text{as } n \to \infty.
$$

---

### Approximation

Rewrite $F_n$ as:

$$
F_n = \frac{\phi^n}{\sqrt{5}} \left(1 - \left(\frac{\psi}{\phi}\right)^n \right).
$$

As $n$ grows large:

$$
\left(\frac{\psi}{\phi}\right)^n \to 0,
$$

so:

$$
F_n \approx \frac{\phi^n}{\sqrt{5}}.
$$

---

### Taking Logarithm (base 10)

$$
\log_{10} F_n \approx \log_{10}\left(\frac{\phi^n}{\sqrt{5}}\right)
= n \log_{10} \phi - \log_{10} \sqrt{5}.
$$

---

### Number of Digits Formula

For any positive integer $N$:

$$
\text{digits}(N) = \lfloor \log_{10} N \rfloor + 1.
$$

Therefore, the number of digits in $F_n$ is:

$$
\boxed{
\left\lfloor n \log_{10} \phi - \log_{10} \sqrt{5} \right\rfloor + 1
}
$$

---

### Important Justification

From Binet’s formula:

$$
F_n = \frac{\phi^n}{\sqrt{5}} - \frac{\psi^n}{\sqrt{5}}.
$$

The second term satisfies:

$$
\left| \frac{\psi^n}{\sqrt{5}} \right| < \frac{1}{2}.
$$

Thus, $F_n$ is the **nearest integer** to:

$$
\frac{\phi^n}{\sqrt{5}}.
$$

This ensures that the digit formula derived from the approximation is **exact**, not just asymptotic.
