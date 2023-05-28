SELECT person_id, count(*) as count_of_visits from person_visits
GROUP BY person_id
ORDER BY count_of_visits DESC, person_id;