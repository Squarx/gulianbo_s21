ALTER TABLE person_discounts
ADD CONSTRAINT ch_nn_person_id CHECK (person_id IS NOT NULL),
ADD CONSTRAINT ch_nn_pizzeria_id CHECK (person_discounts.pizzeria_id IS NOT NULL),
ADD CONSTRAINT ch_nn_discount CHECK (person_discounts.discount IS NOT NULL),
ALTER COLUMN discount SET DEFAULT 0,
ADD CONSTRAINT ch_range_discount CHECK (discount >= 0 AND discount <= 100);

