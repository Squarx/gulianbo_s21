select concat(name, ' (',
    'age:',age,
    ',gender:''', gender,
    ''',address:''', address, ''')'
    ) as person_information
from person
order by person_information;

SELECT name || ' (age:' || age || ',gender:''' || gender || ''',address:''' || address || ''')' as person_information
FROM person
order by person_information;
