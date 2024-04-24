# File Hosting Service (FHS)
**FHS** is a complex project consisted of an ***authz server*** and a ***resource server***. It's an amateur project allowing to dive into the world of the software development.

## Table Of Contents:
1. [Authorization Server](#authz-server)
2. [Resource Server](#resource-server)
    - [Application Programming Interface](#api)
3. [Usage](#usage)

## Authorization Server <a name="authz-server"></a>
It's run on the **8083 port**. The server is responsible for authentication and authorization of clients.

### Key Components
There are three key components to any authz server:
- **Authentication**: handles the verification of the user credentials, such as the ***JWT*** to ensure that only authenticated users can obtain access to the data;
- **Authorization**: verifies if the authenticated user has required permissions to access restricted data. Once verified, access tokens are issued for the respective resource;
- **Token Management**: manages lifecycle, issuance and revocation of the access tokens;

### How does it work?
There are three steps to how an authz server works:
- **Granting authorization**: grants the necessary permissions. After this process the authz server generates an authorization code. Authorization codes are sent to the user by sending them back to the registered redirect URI;
- **Token request**: exchanges user's authorization code for an access token to obtain access to a protected resource. This is known as the ***token request***, whereby the client provides an authorization code, client ID, and client secret (if required). The authz server validates credentials and then issues a token;
- **Accessing protected resources**: once the client has obtained an access token, they can use it to access the protected resource. The client will usually include the access token in the ***Authorization Header*** of future requests. The resource server will validate an access token with the authz server and return the protected resource to the client;

### Protocols
...

### OpenID Connect (OIDC)
...

## Resource Server <a name="resource-server"></a>
Server is listening on the **8080 port**. It manages resources stored in the database.

### Application Programming Interface (API) <a name="api"></a>
We secure our REST API with ***OAuth 2.0*** using ***JWTs***.
...

1. **Auth Controller** (functionalities):
    - register user **POST** {***username***, ***password***};
    - authenticate user **POST** {***username***, ***password***};

2. **Account Controller** (functionalities): <- OPTIONAL
    - change username **PATCH** {***new username***, ***Bearer Token***};
    - change password **PATCH** {***old password***, ***new password***, ***Bearer Token***};

3. **File Controller** (functionalities):
    - upload file **POST** {***file***, ***Bearer Token***};
    - remove file **DELETE** {***file name***, ***Bearer Token***};
    - download file **GET** {***file URI***, ***Bearer Token***};

## Usage <a name="usage"></a>
You're allowed to download and use the project in whatever way you like.
