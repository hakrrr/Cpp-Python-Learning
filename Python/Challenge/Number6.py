# Regex & Overwrite Functions
import re

re.ASCII
regex_integer_in_range = r"[1-9][0-9]{5}$"
regex_alternating_repetitive_digit_pair = r"(?=(\d)\d\1)"
re.findall = lambda ptt, s: len(list(re.finditer(ptt, s)))
# regex_alternating_repetitive_digit_pair = r"(?P<numb>\d)\d(?P=numb)"

print(bool(re.match(regex_integer_in_range, input())))
print(re.findall(regex_alternating_repetitive_digit_pair, input()))
