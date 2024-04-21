# File hosting service (FHS)
**FHS** is a complex project consisted of a ***authz server*** and a ***resource server***. It's an amateur project allowing to dive into the world of the software development.

## Table of contents:
1. [Authorization Server](#authz-server)
2. [Resource Server](#resource-server)
    - [Application Programming Interface](#api)
3. [Usage](#usage)

## Authorization Server <a name="authz-server"></a>
...

## Resource Server <a name="resource-server"></a>

### Application Programming Interface (API) <a name="api"></a>
We secure our REST API with ***OAuth 2.0*** using ***JWTs***.
...

1. **Auth Controller** (functionalities):
    - register user **POST** {***username***, ***password***};
    - authenticate user **POST** {***username***, ***password***};

2. **Account Controller** (functionalities):
    - change username **PATCH** {***new username***, ***Bearer Token***};
    - change password **PATCH** {***old password***, ***new password***, ***Bearer Token***};

3. **File Controller** (functionalities):
    - upload file **POST** {***file***, ***Bearer Token***};
    - remove file **DELETE** {***file name***, ***Bearer Token***};
    - download file **GET** {***file URI***, ***Bearer Token***};

## Usage <a name="usage"></a>
You're allowed to download and use the project in whatever way you like.
