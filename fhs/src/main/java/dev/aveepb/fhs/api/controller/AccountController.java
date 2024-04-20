package dev.aveepb.fhs.api.controller;

import dev.aveepb.fhs.util.requestbody.ChangePasswordRB;
import dev.aveepb.fhs.util.requestbody.ChangeUsernameRB;
import lombok.RequiredArgsConstructor;
import org.springframework.http.RequestEntity;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.PatchMapping;
import org.springframework.web.bind.annotation.RequestMapping;

@Controller
@RequestMapping("/account")
@RequiredArgsConstructor
public class AccountController {

    @PatchMapping("/change-username")
    private ResponseEntity<String> changeUsername(RequestEntity<ChangeUsernameRB> request) {

        return ResponseEntity.ok("REACHED AN EMPTY ENDPOINT...");
    }

    @PatchMapping("/change-password")
    private ResponseEntity<String> changePassword(RequestEntity<ChangePasswordRB> request) {

        return ResponseEntity.ok("REACHED AN EMPTY ENDPOINT...");
    }
}
