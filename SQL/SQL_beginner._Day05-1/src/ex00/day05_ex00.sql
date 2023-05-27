SELECT conname AS constraint_name,
       conrelid::regclass AS table_name,
       a.attname AS column_name,
       confrelid::regclass AS referenced_table_name,
       af.attname AS referenced_column_name
FROM pg_constraint c
JOIN pg_attribute a ON a.attnum = ANY(c.conkey) AND a.attrelid = c.conrelid
JOIN pg_attribute af ON af.attnum = ANY(c.confkey) AND af.attrelid = c.confrelid
WHERE contype = 'f';


CREATE INDEX idx_menu_pizzeria_id ON menu  (pizzeria_id);

CREATE INDEX idx_person_visits_pizzeria_id ON person_visits  (pizzeria_id);
CREATE INDEX idx_person_visits_person_id ON person_visits  (person_id);

CREATE INDEX idx_person_order_person_id ON person_order (person_id);
CREATE INDEX idx_person_order_menu_id ON person_order (menu_id);

