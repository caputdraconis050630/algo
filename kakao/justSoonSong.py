# https://programmers.co.kr/learn/courses/30/lessons/17683

import math


def replace_step(m):
    return m.replace('A#', 'a').replace('C#', 'c').replace("D#", 'd').replace('F#', 'f').replace('G#', 'g')


def solution(m, musicinfos):
    answer = None
    m = replace_step(m)
    max_play_time = 0

    for musicinfo in musicinfos:
        start_time, end_time, name, melody = musicinfo.split(',')
        play_time = (int(end_time[:2]) * 60 + int(end_time[3:])) - \
            (int(start_time[:2] * 60) + int(start_time[3:]))

        melody = replace_step(melody)
        melody_repeated_count = math.ceil(play_time / len(melody))
        melody_played = (melody * melody_repeated_count)[:play_time]

        if m in melody_played and play_time > max_play_time:
            answer = name
            max_play_time = play_time

    if not answer:
        return "(None)"
    return answer
