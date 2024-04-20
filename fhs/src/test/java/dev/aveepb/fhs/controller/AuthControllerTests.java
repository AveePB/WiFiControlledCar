package dev.aveepb.fhs.controller;

import dev.aveepb.fhs.util.requestbody.AuthRB;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.boot.test.web.client.TestRestTemplate;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;

import static org.assertj.core.api.Assertions.assertThat;

@SpringBootTest(webEnvironment = SpringBootTest.WebEnvironment.RANDOM_PORT)
public class AuthControllerTests {

    @Autowired
    public TestRestTemplate restTemplate = null;

    @Test
    void shouldSuccessfullyRegisterAUser() {
        //Arrange
        AuthRB body = new AuthRB("Jack", "MyPassword1231");

        //Act
        ResponseEntity<String> response = restTemplate.postForEntity("/auth", body, String.class);

        //Assert
        assertThat(response.getStatusCode()).isEqualTo(HttpStatus.OK);
    }
}
