package $name;format="camel"$

import com.natpryce.hamkrest.and
import com.natpryce.hamkrest.assertion.assertThat
import org.http4k.client.OkHttp
import org.http4k.core.Request
import org.http4k.core.Response
import org.http4k.core.Method.GET
import org.http4k.core.Method.POST
import org.http4k.core.Status.Companion.OK
import org.http4k.hamkrest.hasBody
import org.http4k.hamkrest.hasStatus
import org.junit.jupiter.api.AfterEach
import org.junit.jupiter.api.BeforeEach
import org.junit.jupiter.api.Test

class AppTest {
    private val client = OkHttp()
    private val server = App.counterServer()

    @BeforeEach
    fun setup() {
        server.start()
    }

    @AfterEach
    fun teardown() {
        server.stop()
    }

    @Test
    fun `all endpoints are mounted correctly`() {
        client(Request(GET, "http://localhost:\${server.port()}/counter")).answerShouldBe(0)
        client(Request(POST, "http://localhost:\${server.port()}/increment")).answerShouldBe(1)
        client(Request(POST, "http://localhost:\${server.port()}/increment")).answerShouldBe(2)
        client(Request(POST, "http://localhost:\${server.port()}/decrement")).answerShouldBe(1)
    }

    private fun Response.answerShouldBe(expected: Int) {
        assertThat(this, hasStatus(OK).and(hasBody(expected.toString())))
    }
}