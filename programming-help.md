https://stackoverflow.com/questions/29163805/member-objects-as-unique-ptr-or-on-stack

https://en.wikipedia.org/wiki/Entity_component_system#:~:text=Entity%3A%20The%20entity%20is%20a,it%20interacts%20with%20the%20world.

https://softwareengineering.stackexchange.com/questions/133159/entity-component-system-architecture-interaction-between-systems

https://stackoverflow.com/questions/34072862/why-is-error-invalid-application-of-sizeof-to-an-incomplete-type-using-uniqu

Aggregation in classes is best done using const references, this way, the concrete pointer towards it is abstracted from it, as well as keeping it const is easier