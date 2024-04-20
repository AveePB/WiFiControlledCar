package dev.aveepb.fhs.api.controller;

import dev.aveepb.fhs.util.requestbody.AuthRB;
import lombok.RequiredArgsConstructor;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;

@Controller
@RequestMapping("/auth")
@RequiredArgsConstructor
public class AuthController {

    @PostMapping("/register")
    private ResponseEntity<String> registerUser(@RequestBody AuthRB body) {

        return ResponseEntity.ok("REACHED AN EMPTY ENDPOINT...");
    }

    @PostMapping("/authenticate")
    private ResponseEntity<String> authenticateUser(@RequestBody AuthRB body) {

        return ResponseEntity.ok("REACHED AN EMPTY ENDPOINT...");
    }
}
