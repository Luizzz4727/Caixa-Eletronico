#!/usr/bin/env python3
"""Validação local da lógica de commonSubstring."""


def has_common_character(s1: str, s2: str) -> bool:
    seen = [False] * 26
    for c in s1:
        seen[ord(c) - ord("a")] = True
    for c in s2:
        if seen[ord(c) - ord("a")]:
            return True
    return False


def common_substring(a: list[str], b: list[str]) -> list[str]:
    return ["YES" if has_common_character(x, y) else "NO" for x, y in zip(a, b)]


def main() -> None:
    a = ["ab", "cd", "ef"]
    b = ["af", "ee", "ef"]
    expected = ["YES", "NO", "YES"]
    got = common_substring(a, b)

    print("Entrada a:", a)
    print("Entrada b:", b)
    print("Esperado:", expected)
    print("Obtido:  ", got)
    assert got == expected, f"Falhou: {got} != {expected}"
    print("OK — exemplo passou.")

    # Casos extras
    extras = [
        (["a"], ["b"], ["NO"]),
        (["xyz"], ["zyx"], ["YES"]),
        (["hello", "world"], ["xyz", "word"], ["NO", "YES"]),
        (["aaaa"], ["bbbb"], ["NO"]),
        (["abc"], ["c"], ["YES"]),
    ]
    for aa, bb, exp in extras:
        res = common_substring(aa, bb)
        assert res == exp, f"Falhou {aa}/{bb}: {res} != {exp}"
        print(f"OK — {aa} x {bb} -> {res}")


if __name__ == "__main__":
    main()
