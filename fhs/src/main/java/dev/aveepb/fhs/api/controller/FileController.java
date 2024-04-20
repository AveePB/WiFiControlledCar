package dev.aveepb.fhs.api.controller;

import dev.aveepb.fhs.util.requestbody.UploadFileRB;
import lombok.RequiredArgsConstructor;
import org.springframework.http.RequestEntity;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.*;

@Controller
@RequestMapping("/files")
@RequiredArgsConstructor
public class FileController {

    @PostMapping
    private ResponseEntity<String> uploadFile(RequestEntity<UploadFileRB> request) {

        return ResponseEntity.ok("REACHED AN EMPTY ENDPOINT...");
    }

    @DeleteMapping("/{username}/{fileName}")
    private ResponseEntity<String> deleteFile(RequestEntity<Object> request, @PathVariable String username, @PathVariable String fileName) {

        return ResponseEntity.ok("REACHED AN EMPTY ENDPOINT...");
    }

    @GetMapping("/{username}/{fileName}")
    private ResponseEntity<String> downloadFile(@PathVariable String username, @PathVariable String fileName) {

        return ResponseEntity.ok("REACHED AN EMPTY ENDPOINT...");
    }
}
