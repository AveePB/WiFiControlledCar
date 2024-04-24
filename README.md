# File Hosting Service (FHS)
**FHS** is a complex project consisted of an ***authz server*** and a ***resource server***. It's an amateur project allowing to dive into the world of the software development.

## Table Of Contents:
1. [Authorization Server](#authz-server)
    - [Key Components](#authz-server-key-components)
    - [How does it work?](#authz-server-how-does-it-work)
    - [Access token](#authz-server-access-token)
    - [OpenID Connect](#authz-server-oidc)
2. [Resource Server](#resource-server)
    - [Application Programming Interface](#api)
3. [Usage](#usage)

## Authorization Server <a name="authz-server"></a>
It's a server that is responsible for the ***authentication and authorization*** of clients. It manages the access to protected data by verifying clients and issuing tokens. It runs on the **8083** port.

### Key Components <a name="authz-server-key-components"></a>
There are three key components to any authz server:
- **Authentication**: handles the verification of the user credentials, such as the ***JWT*** or a user password to ensure that only authenticated users can obtain access to the data;
- **Authorization**: ensures that the authenticated user has required permissions to access restricted data. Once verified, access tokens are issued for the respective resource;
- **Token Management**: manages lifecycle, issuance and revocation of the access tokens;

### How does it work? <a name="authz-server-how-does-it-work"></a>
There are three steps to how an authz server works:
- **Granting authorization**: grants the necessary permissions. After this process the authz server generates an authorization code. Authorization codes are sent to the user by sending them back to the registered redirect URI;
- **Token request**: exchanges user's authorization code for an access token to obtain access to a protected resource. The client provides an authorization code, client ID, and client secret (if required). The authz server validates credentials and then issues a token;
- **Accessing protected resources**: once the client has obtained an access token, they can use it to access the protected resource. The client will usually include the access token in the ***Authorization Header*** of a request. The resource server will validate an access token with the authz server and return the protected resource to the client;

### Access Token <a name="authz-server-access-token"></a>
Access tokens are used in token-based authentication to secure the API. Clients receive access tokens after the successfull authentication and authorization. 

Access Token is used as the credential while calling the target API. The passed token informs the API that the bearer of the token has permissions to perform some actions specified by the ***Scope*** that was granted during the authorization. 

### OpenID Connect (OIDC) <a name="authz-server-oidc"></a>
OpenID Connect is an open and trusted authentication protocol that is an additional identity layer. An authz server issues ***id tokens*** alongside access tokens, providing a user authentication and an identity information in a single transaction. Those ***id tokens*** allow clients to ask a server about their basic information.

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
